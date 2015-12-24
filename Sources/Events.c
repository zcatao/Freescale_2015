


#include "Include.h"

unsigned char g_PIT_time_flag = 0;

unsigned char SpeedControlCount = 0;

unsigned char DirectionControlCount = 0;

unsigned char g_SCI1_READ_flag = 0 ;

unsigned char CCD_TimerCnt20ms = 0;

unsigned char CCD_Capture_flag = 0;

unsigned char duty = 0;

unsigned char Start_Flag = 0;

unsigned long long StartPulseCnt;

uint32_t MsTimeCount = 0;

uint16_t TEST_Count; 

#pragma CODE_SEG __NEAR_SEG NON_BANKED
interrupt VectorNumber_Vpit0  void PIT_ISR1(void)
{
	PITTF_PTF0 = 1;										// clear Interrupt flag
	EnableInterrupts;
	MsTimeCount++;


    if (g_PIT_time_flag == 0)
    {
		AD_Capture();
    }
    if (g_PIT_time_flag == 1)
    {
		AngelCalculate();

		AngelAdjust();

		SpeedControlOutCount++;

		DirectionControlOutCount++;

		SpeedControlOut();

		DirectionControlout();

		Motor_out();
    }
    if (g_PIT_time_flag == 2)
    {

		DirectionControlCount++;	

		PixelDifference(Pixel,PixelDiff);

		Get_Line2();

		if (DirectionControlCount >= 2)
		{
			DirectionControlCount = 0;
			DirectionControlOutCount = 0;
			DirectionControl();
		}
	}
    if (g_PIT_time_flag == 3)
    {
        SpeedControlCount++;
        if (SpeedControlCount >= 20)
        {
            SpeedControl();

			SpeedControlCount = 0;

            SpeedControlOutCount = 0;
        }
		//SendImageData(PixelDiff);
		
    }
    if (g_PIT_time_flag++ >= 4)
    {
		 Speed_Read();
		 ImageCapture(Pixel);
		 g_PIT_time_flag = 0;
    }
	
	/*if (integration_point >= 1)
	{
		if ( == CCD_TimerCnt20ms &&
			CCD_Capture_flag == 0)
		{
			StartIntegration();
		}
	}*/
	if (integration_point == CCD_TimerCnt20ms &&
		CCD_Capture_flag == 0)
	{
		//StartIntegration();
		;
		//CCD_Capture_flag = 1;
	}
	if (CCD_TimerCnt20ms++ >= IntegrationTime){

		//ImageCapture(Pixel);
		//AngelCalulate_AR2();
		CCD_TimerCnt20ms = 0;
		CCD_Capture_flag = 1;

	}
	Car.OE_Tube1_Value = ATD0_Read(14);
	Car.OE_Tube2_Value = ATD0_Read(15);
	SpeedDowmLineDetection();
	//SPR = (RightAngle_flag + 1) % 2;

}
#pragma CODE_SEG DEFAULT

#pragma CODE_SEG __NEAR_SEG NON_BANKED
interrupt VectorNumber_Vportj void PJ0_ISR(void)
{
	
	PIFJ_PIFJ0 = 1;

	Start_Flag = 1;

	StartPulseCnt++;
}
#pragma CODE_SEG DEFAULT
//
//#pragma CODE_SEG __NEAR_SEG NON_BANKED
//void  interrupt 21 SCIbu1_re(void)
//{
//
//    static i = 0;
//    unsigned char ch;
//    ch = SCI1_Read();
//	SCI1_Send(ch);
//    if (ch == SEND_HEAD)
//    {
//       i = 0;
//    }
//    g_STBuf[i++] = ch;
//    if (i == 4)
//    {
//        i = 0;
//        g_SCI1_READ_flag = 1;
//    }
//}
//#pragma CODE_SEG DEFAULT
