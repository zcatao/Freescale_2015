

#include "Sources\Include.h"
int    max, min, threshold;
double   threshold_ratio = 0.5;
int m1 = 32, m2 = 96, m[] = { 64, 64, 64, 64 };
int b0 = 0, speed = 45;
double K_p = 2.1, K_i = 0, K_d = 0.5;
int digit[128];
int duty[] = {
	1056, 1063, 1070, 1077, 1084, 1091, 1098, 1105, 1112, 1118, 1125, 1132, 1139, 1146, 1153, 1160,
	1167, 1174, 1181, 1188, 1195, 1202, 1209, 1216, 1223, 1229, 1236, 1243, 1250, 1257, 1264, 1271,
	1278, 1285, 1292, 1299, 1306, 1313, 1320, 1327, 1334, 1340, 1347, 1354, 1361, 1368, 1375, 1382,
	1389, 1396, 1403, 1410, 1417, 1424, 1431, 1438, 1445, 1451, 1458, 1465, 1472, 1479, 1486, 1493,
	1500, 1507, 1514, 1521, 1528, 1535, 1542, 1549, 1556, 1562, 1569, 1576, 1583, 1590, 1597, 1604,
	1611, 1618, 1625, 1632, 1639, 1646, 1653, 1660, 1667, 1673, 1680, 1687, 1694, 1701, 1708, 1715,
	1722, 1729, 1736, 1743, 1750, 1757, 1764, 1771, 1778, 1784, 1791, 1798, 1805, 1812, 1819, 1826,
	1833, 1840, 1847, 1854, 1861, 1868, 1875, 1882, 1889, 1895, 1902, 1909, 1916, 1923, 1930, 1937 }; //占空比，查表
/*************************************************
函数名: void MidFilterint(void)
功能:  加权快速中值滤波
参数:无
返回值:无
**************************************************/
void MidFilterint(void){           //加权快速中值滤波
	int i, old = 0, average, mid, temp = 0;
	CCD[0] = CCD[2];             //滤掉第一个和第二个跳变的噪波
	CCD[1] = CCD[2];
	for (i = 1; i<127; i++){
		if (old == CCD[i + 1]){
			CCD[i] = temp;
		}
		else{
			if ((CCD[i - 1]>CCD[i] && CCD[i - 1]<CCD[i + 1]) || (CCD[i - 1]>CCD[i + 1] && CCD[i - 1]<CCD[i])){
				mid = CCD[i - 1];
			}
			else if ((CCD[i]>CCD[i - 1] && CCD[i]<CCD[i + 1]) || (CCD[i]>CCD[i + 1] && CCD[i]<CCD[i - 1])){
				mid = CCD[i];
			}
			else if ((CCD[i + 1]>CCD[i] && CCD[i + 1]<CCD[i - 1]) || (CCD[i + 1]>CCD[i - 1] && CCD[i + 1]<CCD[i])){
				mid = CCD[i + 1];
			}
			else{
				mid = CCD[i];
			}
			average = (CCD[i - 1] + CCD[i] + CCD[i + 1]) / 3;
			temp = 0.3*mid + 0.7*average;
			CCD[i] = temp;
		}
		old = CCD[i - 1];
	}
}
/*************************************************
函数名: void filterint(void)
功能:   滑动均值滤波和中值滤波相结合的去噪滤波
参数:无
返回值:无
**************************************************/
void filterint(void){           //滑动均值滤波和中值滤波相结合的去噪滤波
	int i;
	CCD[0] = CCD[2];             //滤掉第一个和第二个跳变的噪波
	CCD[1] = CCD[2];
	for (i = 0; i<126; i++){                     //滑动均值滤波
		if (CCD[i] == CCD[i + 1] || CCD[i] == CCD[i + 2] || CCD[i + 1] == CCD[i + 2]){
			CCD[i + 1] = (CCD[i] + CCD[i + 1] + CCD[i + 2]) / 3;
		}
		else{                                   //中值滤波
			if (CCD[i]>CCD[i + 2]){
				if (CCD[i + 1]>CCD[i]){
					CCD[i] = CCD[i + 1];
				}
				else if (CCD[i + 1]<CCD[i + 2]){
					CCD[i + 2] = CCD[i + 1];
				}
			}
			else{
				if (CCD[i + 1]<CCD[i]){
					CCD[i] = CCD[i + 1];
				}
				else if (CCD[i + 1]>CCD[i + 2]){
					CCD[i + 2] = CCD[i + 1];
				}
			}
			CCD[i + 1] = (CCD[i] + CCD[i + 2]) / 2;
		}
	}
}
/*************************************************
函数名: void SmallBinaryzation(void)
功能:   简单的二值化
参数:无
返回值:无
**************************************************/
void SmallBinaryzation(void){
	int i;
	max = 0, min = 4000;

	for (i = 0; i<128; i++){
		if (CCD[i]>max){
			max = CCD[i];
		}
		if (CCD[i]<min){
			min = CCD[i];
		}
	}

	threshold = (max + min)*threshold_ratio;          //定阈值

	for (i = 0; i<128; i++){
		if (CCD[i]>threshold){
			digit[i] = 1;
		}
		else{
			digit[i] = 0;
		}
	}

}
/*************************************************
函数名: void PID(void)
功能:   PID舵机转向
参数:无
返回值:无
**************************************************/
void PID(void){

	/*  double a0=K_p+K_d+K_i;
	double a1=-K_p-2*K_d;
	double a2=K_d;  */

	int temp;
	int e[4];
	int e_d;

	get_leftboder(m[3]);
	get_rightboder(m[3]);

	/*if(m1==0){
	m[3]=m2-64;
	}else if(m2==128){
	m[3]=m1+64;
	}else {
	m[3]=(m1+m2)/2;
	} */
	m[3] = (m1 + m2) / 2;

	//temp=(m[3]-64)*a0+(m[2]-64)*a1+(m[1]-64)*a2;
	//temp=(m[2]-64)*K_p;
	//temp=(m[2]-64)*a0+(m[0]-64)*a2;
	e[3] = m[3] - 64;
	e[2] = m[2] - 64;
	e[1] = m[1] - 64;
	e[0] = m[0] - 64;
	e_d = e[3] - e[0];
	temp = (e[3])*K_p + (e[3] + e[2] + e[1] + e[0])*K_i + (e_d)*K_d;

	if (temp>63){                //必要限幅
		temp = 63;
	}
	else if (temp<-64){
		temp = -64;
	}

	/* u+=temp;
	if(u>128){
	u=127;
	}else if(u<0){
	u=0;
	}  */

	STEER_run(duty[64 + temp]);

	if (temp<10 && temp>-10){
		Motor_run(speed + 15);
	}
	else if (temp<25 && temp>-25) {
		Motor_run(speed);
	}
	else{
		Motor_run(speed - 15);
	}

	m[0] = m[1];
	m[1] = m[2];
	m[2] = m[3];

}
/*************************************************
函数名: int get_leftboder(int start)
功能:   获取左边线
参数:
返回值:
**************************************************/
void get_leftboder(int start){
	int i = 0;
	for (i = start; i>3; i--){
		if ((digit[i] == 0) && (digit[i - 1] == 0) && (digit[i - 2] == 0) && (digit[i - 3] == 0))  {
			m1 = i - 1;
			return;
		}
	}
	m1 = 0;
}

/*************************************************
函数名:  int get_rightboder(int start)
功能:   获取右边线
参数:
返回值:
**************************************************/
void get_rightboder(int  start) {
	int  i = 0;
	for (i = start; i<125; i++){
		if ((digit[i] == 0) && (digit[i + 1] == 0) && (digit[i + 2] == 0) && (digit[i + 3] == 0)) {
			m2 = i + 1;
			return;
		}
	}
	m2 = 128;
}
