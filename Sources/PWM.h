/*
*********************************************************************************************************
*
*                                      MCU: MC9S12XS128MAL - 112Pin
*                                      OSC: 16.000MHz
*                                      BUS: 32.0MHz
*
* File : PWM.h
* By   : atao
*********************************************************************************************************
*/

#ifndef PWM_H_
#define PWM_H_

#define PWM_PRCLK 0X33              //(BUS_FREQ / CH_A_FREQ) = 4 ; (BUS_FREQ / CH_B_FREQ) = 4

#define CH_A_FREQ 8000000           //	The frequnncy of clock A

#define CH_B_FREQ 8000000           //	The frequnncy of clock B

#define CH_SA_FREQ 1000000          //	The frequnncy of clock SA

#define CH_SB_FREQ 1000000          //	The frequnncy of clock SB

#define CH_SA_DIV (CH_A_FREQ / (CH_SA_FREQ * 2))   //(CH_SA_DIV = 4)

#define CH_SB_DIV (CH_B_FREQ / (CH_SB_FREQ * 2))   //(CH_SB_DIV = 4)

#define Motor_FREQ 5000             //	The frequnncy of DC

void PWM_Init(void);

void Motor_forward_0(uint8_t);

void Motor_forward_1(uint8_t);

void Motor_back_0(uint8_t);

void Motor_back_1(uint8_t);

void Motor_brake(void);

#endif
