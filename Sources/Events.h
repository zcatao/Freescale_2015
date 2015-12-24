/*
*********************************************************************************************************
*
*                                      MCU: MC9S12XS128MAL - 112Pin
*                                      OSC: 16.000MHz
*                                      BUS: 32.0MHz
*
* File : Events.c
* By   : atao
*********************************************************************************************************
*/
#ifndef EVENTS_H_
#define EVENTS_H_


extern unsigned char TimerFlag20ms;

extern uint32_t MsTimeCount;

extern unsigned char g_SCI1_READ_flag;
	
extern unsigned char IntegrationTime;

extern unsigned char integration_point;

extern unsigned char SpeedControlOutCount;

extern unsigned char DirectionControlOutCount;

extern unsigned char CCD_Capture_flag;

extern unsigned char CCD_TimerCnt20ms;

extern unsigned char duty;

extern unsigned char Start_Flag;

extern unsigned long long StartPulseCnt;


#pragma CODE_SEG __NEAR_SEG NON_BANKED

__interrupt void PIT_ISR1(void);

#pragma CODE_SEG DEFAULT

#pragma CODE_SEG NON_BANKED

__interrupt void PJ0_ISR(void);

#pragma CODE_SEG DEFAULT




#endif
