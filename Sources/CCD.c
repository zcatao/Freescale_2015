/*
*********************************************************************************************************
*
*                                      MCU: MC9S12XS128MAL - 112Pin
*                                      OSC: 16.000MHz
*                                      BUS: 32.0MHz
*
*
* File : CCD.c
* By   : atao
*********************************************************************************************************
*/

#include "Include.h"


unsigned char Pixel[128];

unsigned char PixelDiff[128];
/* 128个像素点的平均AD值 */
unsigned char PixelAverageValue;
/* 128个像素点的平均电压值的10倍 */
unsigned char PixelAverageVoltage;

/* 设定目标平均电压值，实际电压的10倍 */
int TargetPixelAverageVoltage = 40;
/* 设定目标平均电压值与实际值的偏差，实际电压的10倍 */
int PixelAverageVoltageError = 0;
/* 设定目标平均电压值允许的偏差，实际电压的10倍 */
int TargetPixelAverageVoltageAllowError = 5;

/* 曝光时间，单位ms */
unsigned char IntegrationTime = 10;

unsigned char Line_L;

unsigned char Line_R;

unsigned char Middle_Line;

unsigned char Line_R_Miss;

unsigned char Line_L_Miss;

unsigned char Single_Line_Boot_Flag;


void ImageCapture(unsigned char * ImageData) {

	unsigned char i;
	unsigned int  temp_int;
	TSL1401_SI = 1;         /* SI  = 1 */
	SamplingDelay();
	TSL1401_CLK = 1;        /* CLK = 1 */
	SamplingDelay();
	TSL1401_SI = 0;         /* SI  = 0 */
	SamplingDelay();

	//Delay 20us for sample the first pixel

	for (i = 0; i < 50; i++) {                //更改25，让CCD的图像看上去比较平滑，
		Cpu_Delay1us();                      //把该值改大或者改小达到自己满意的结果。
	}
	/*  SamplingDelay();
	SamplingDelay();*/

	//Sampling Pixel 1
	temp_int = ATD0_Read(6);
	*ImageData++ = (byte)(temp_int >> 4);
	TSL1401_CLK = 0;        /* CLK = 0 */

	for (i = 0; i < 127; i++) {
		SamplingDelay();
		SamplingDelay();
		TSL1401_CLK = 1;    /* CLK = 1 */
		SamplingDelay();
		SamplingDelay();
		//Sampling Pixel 2~128
		temp_int = ATD0_Read(6);
		*ImageData++ = (byte)(temp_int >> 4);
		TSL1401_CLK = 0;    /* CLK = 0 */
	}

	SamplingDelay();
	SamplingDelay();
	TSL1401_CLK = 1;        /* CLK = 1 */
	SamplingDelay();
	SamplingDelay();
	TSL1401_CLK = 0;        /* CLK = 0 */
}

void CalculateIntegrationTime() {

    /* 计算128个像素点的平均AD值 */
    //PixelAverageValue = PixelAverage(128,Pixel);
	PixelAverageValue = PixelMaxValue(6, 120, Pixel);
    /* 计算128个像素点的平均电压值,实际值的10倍 */
    PixelAverageVoltage = (unsigned char)((int)PixelAverageValue * 25 / 128);

    PixelAverageVoltageError = TargetPixelAverageVoltage - PixelAverageVoltage;
    if(PixelAverageVoltageError < -TargetPixelAverageVoltageAllowError)
        IntegrationTime--;
    if(PixelAverageVoltageError > TargetPixelAverageVoltageAllowError)
        IntegrationTime++;
    if(IntegrationTime <= 1)
        IntegrationTime = 1;
    if(IntegrationTime >= 20)
        IntegrationTime = 20;

	integration_point = (20 - IntegrationTime);

///    SCI0_SendChar1(0xaa);
//    SCI0_SendChar1(PixelAverageVoltage);
//    SCI0_SendChar1(IntegrationTime);
}

void PixelDifference(unsigned char *Image,
	unsigned char *Diff){

	unsigned char i = 0;
	int temp;

	Diff[0] = 127;

	for (i = 1; i < 128; i++){
		temp = Image[i] - Image[i - 1] + 127;
		if (temp > 0xff){
			Diff[i] = 0xff;
		}
		else if (temp < 0){
			temp = 0;
		}
		else{
			Diff[i] = (unsigned char)temp;
		}
	}
}

unsigned char PixelMaxValue(unsigned char l, 
							unsigned char r, 
							unsigned char *data)
{
	unsigned char i;
	unsigned char max = 0;
	for (i = l; i < r; i++){
		if (max < *(data + i)){
			max = *(data + i);
		}
	}
	Pixel[0] = max;
	return max;
}
unsigned char PixelAverage(unsigned char len, unsigned char *data) {
  unsigned char i;
  unsigned int sum = 0;
  for(i = 0; i<len; i++) {
    sum = sum + *data++;
  }
  return ((unsigned char)(sum/len));
}


void StartIntegration(void) {

	unsigned char i;

	TSL1401_SI = 1;         /* SI  = 1 */
	SamplingDelay();
	TSL1401_CLK = 1;        /* CLK = 1 */
	SamplingDelay();
	TSL1401_SI = 0;         /* SI  = 0 */
	SamplingDelay();
	TSL1401_CLK = 0;        /* CLK = 0 */

	for (i = 0; i<127; i++) {
		SamplingDelay();
		SamplingDelay();
		TSL1401_CLK = 1;    /* CLK = 1 */
		SamplingDelay();
		SamplingDelay();
		TSL1401_CLK = 0;    /* CLK = 0 */
	}
	SamplingDelay();
	SamplingDelay();
	TSL1401_CLK = 1;        /* CLK = 1 */
	SamplingDelay();
	SamplingDelay();
	TSL1401_CLK = 0;        /* CLK = 0 */
}

void CCD_IO_Init(void)
{
    TSL1401_CLK_DDR = 1;
    TSL1401_SI_DDR  = 1;
    TSL1401_CLK = 0;
    TSL1401_SI  = 0;
}

void Get_Line(){

	unsigned char i;

	unsigned char j;

	int16_t delta;

	unsigned char max;

	max = PixelMaxValue(6, 120, Pixel);

	//Pixel[0] = max;

	for (i = 6; i < 120; i++){
		unsigned char delta1;
		unsigned char delta2;
		if (Pixel[i] > Pixel[i + 2] + 20){

			delta1 = max - Pixel[i - 8];
			delta2 = max - Pixel[i + 12];

			if (delta1 < 20 && delta2 < 20){

				Single_Line_Boot_Flag = 1;
				
				Middle_Line = i + 2;

				return;
			}
		}
	}
	if (Single_Line_Boot_Flag == 1){
		return;
	}
	Single_Line_Boot_Flag = 0;
	//Middle_Line = 63;
	for (i = Middle_Line; i > 6; i --){
		if ((Pixel[i] - Pixel[i - 2]) > 30){
			
			Line_L = i - 2;
			Line_L_Miss = 0;
			break;
		}
	}
	if (i == 6){
		Line_L = 6;
		Line_L_Miss = 1;
	}
	for (j = Middle_Line; j < 120; j ++){
		if (Pixel[j] > Pixel[j + 2] + 30){

			Line_R = j + 2;
			Line_R_Miss = 0;

			break;
		}
	}
	if ( j == 120){

		Line_R = 120;
		Line_R_Miss = 1;
	}

	Middle_Line = (Line_L + Line_R) / 2;

	//Middle_Line -= 4;
	
}
