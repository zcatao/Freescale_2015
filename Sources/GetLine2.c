/**************************************/
/*		直道赛道宽度 len = 90 - 36 = 54*/	
/*		黑线宽度  lem— = 5			  */





#include "Include.h" 



const unsigned char  DiffMinTsdValue = 20;

unsigned char Diff_max;

unsigned char Diff_min;


unsigned char  PixelMaxDIff(unsigned char l, unsigned char r,
	unsigned char *Data){

	unsigned char  i;
	unsigned char max = 0;
	for (i = l; i < r; i++){
		if (Data[max] < Data[i]){
			max = i;
		}
	}
	return max;
}
	
unsigned char PixelMinDiff(unsigned char l, unsigned char r,
	unsigned char *Data){

	unsigned char  i;
	unsigned char min = 0;
	for (i = l; i < r; i++){
		if (Data[min] > Data[i]){
			min = i;
		}
	}
	return min;
}

//高脉冲 返回 1；
//负脉冲 返回 -1；
//没有脉冲返回0；
char SeekPulse(unsigned char Data){

	if (Data > Diff_max * 0.7 + 127 * 0.3&&
		Data > DiffMinTsdValue + 127){

		return 1;
	}
	if (Data < Diff_min * 0.7 + 127 * 0.3&&
		Data < 127 - DiffMinTsdValue){

		return -1;
	}
	
	return 0;
}
void Get_Line2()
{
	//搜索起始偏移量
	const unsigned char Search_Offset = 20;
	//寻左线搜索起始点
	const unsigned char Search_Start_L = Middle_Line + Search_Offset;
	//寻右线搜索起始点
	const unsigned char Search_Start_R = Middle_Line - Search_Offset;


	//引导线允许的变化量
	const  char LineAllowError = 5;

	unsigned char i = 0;

	unsigned char Line_R_new;

	unsigned char Line_L_new;

	unsigned char Single_R = 0;

	unsigned char Single_L = 0;

	char len = 0;

	Diff_max = PixelMaxDIff(4, 124, PixelDiff);

	Diff_min = PixelMinDiff(4, 124, PixelDiff);

	for (i = Search_Start_L; i > 6; i--){
		if (PixelDiff[i] > PixelDiff[Diff_max] * 0.7 + 127 * 0.3&&
			PixelDiff[i] > DiffMinTsdValue + 127){
			Line_L_new = i;
			Line_L_Miss = 0;
			break;
		}
	}
	if (i == 6){
		Line_L_Miss = 1;
		Line_L_new = 6;
	}
	for (i = Search_Start_R; i < 120; i++){
		if (PixelDiff[i] < PixelDiff[Diff_min] * 0.7 + 127 * 0.3&&
			PixelDiff[i] < 127 - DiffMinTsdValue){
			Line_R_new = i;
			Line_R_Miss = 0;
			break;
		}
	}
	if (i == 120){
		Line_R_Miss = 1;
		Line_R_new = 120;
	}
	 
	len = Line_R_new - Line_L_new;

	if (len < 5){
		//if (Line_R - Line_R_new > LineAllowError ||
		//	Line_R_new - Line_R < LineAllowError ||
		//	Line_L - Line_L_new > LineAllowError ||
		//	Line_L_new - Line_L < LineAllowError ){
		//	Single_Line_Boot_Flag = 1;
		//}
		//else{
		//	Single_Line_Boot_Flag = 0;
		//}
		Single_Line_Boot_Flag = 1;
	}
	else{
		Single_Line_Boot_Flag = 0;
	}

	Line_R = Line_R_new;

	Line_L = Line_L_new;

	if (Line_L_Miss && Line_R_Miss)

		Middle_Line = 62;
	else 
		Middle_Line = (Line_R + Line_L) / 2;

}