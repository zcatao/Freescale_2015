#include "hidef.h"      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */

#include "Include.h"



#define START  PTJ_PTJ0
#define START_dir   DDRJ_DDRJ0

int Speed_Set = 0;

void Interrupt_Priority_Set(void){
	INT_CFADDR = 0x70;					//选择PIT0中断组
	INT_CFDATA5 = 0x05;					//设置 A/2 = 5 为第五优先级

	INT_CFADDR = 0xC0;					//选择PTJ中断组C
	INT_CFDATA6 = 0x07;					//设置  E/2 = 7 为第六优先级
}




void main(void) {
   uint8_t i = 0;
	SetBusCLK_64M();
	PIT_Init();
	SCI1_Init();
	//SCI0_Init();
	PWM_Init();
	oled_Init();
	Pulse_Init();
	CCD_IO_Init();
	ATD0_Init();
	SPR_init();

	
	Middle_Line = 62;
	//wakka



	Control_Info.MotorStop =  1;
	Control_Info.Angel_P = 20; //27;//20	;// 9; // 9.5;
	Control_Info.Angel_D = 0.46;//6;//0.46;//0.18;//0.12;
	//5  2.5                  5.4  1.8
	Control_Info.Speed_P = 4 ;// 4;// 5;//0.3;
	Control_Info.Speed_I = 0.37;// 0.45; //0.5;//0.01;
	Control_Info.Speed_D = 0; //0.015;
	Control_Info.Speed_set = 0;


	Control_Info.Direction_P = 0.5;
	Control_Info.Direction_D = 0.1;

	//speed     P      D
	//  20     3.4      0.2
	//  30	   4.5      2.4
	//  40
	//  


	LED_P6x8Str(1,1,"Hohai University");
	MsTimeCount = 0;
	IntegrationTime = 5;
	Speed_Set = 30;

	DDRJ_DDRJ0 = 0;
	PIEJ_PIEJ0 = 1;
	PPSJ_PPSJ0 = 1;

	Start_Flag = 0;
	StartPulseCnt = 0;
	EnableInterrupts;
	
	for (;;){
		
		static unsigned int Time;
		static unsigned long long Pulse_Cnt;

		LED_P6x8Value4(0, 2, StartPulseCnt);
		LED_P6x8Value4(0, 3, Pulse_Cnt);

		Key_Scan();

		if (Start_Flag == 1 &&
			MsTimeCount > Time + 10){

			if (Pulse_Cnt == StartPulseCnt && 
				StartPulseCnt > 10){

				break;		//发车

			}
			else

				Pulse_Cnt = StartPulseCnt;

			Time = MsTimeCount;

		}
		if (MsTimeCount > 3000){
			break;
		}
	}

	PIEJ_PIEJ0 = 0;

	//Speed_Set = -30;
	Control_Info.Speed_set = -Speed_Set;
	Control_Info.Direction_P = 3;//10;//9;  //4.5
	Control_Info.Direction_D = 0.3;// -0.6;//-0.5;//0.24
	//PRM_LED_PUTOUT();
	LED_P6x8Str(0, 3, "L_miss: ");
	LED_P6x8Str(0, 4, "R_miss: ");
	//LED_P6x8Str(64, 6, "S_Fg:");

	for(;;) { 
	 
	  LED_P6x8Value4(0, 2, Car.OE_Tube1_Value);
	  LED_P6x8Value4(64, 2, Car.OE_Tube2_Value);
	  PRM_LED_PUTOUT();

	   SPR = (RightAngle_flag + 1) % 2;

	   OutData[0] = Car.Speed_R * 100;
	   OutData[1] = Car.Speed_L * 100;
	   OutData[2] = Car.Gyro_Y * 100;
	   OutData[3] = Car.Gyro_AR1 * 100;
	   
	   //OutData[3] = Car.Gyro_Y;
	   //OutPut_Data();
	   SendImageData(Pixel);
	}
}
	