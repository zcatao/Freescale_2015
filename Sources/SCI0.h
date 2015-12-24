/*
*********************************************************************************************************
*
*                                      MCU: MC9S12XS128MAL - 112Pin
*                                      OSC: 16.000MHz
*                                      BUS: 32.0MHz
*                 					  BAUD:	9600
*
* File : SCI1.h
* By   : atao
*********************************************************************************************************
*/

#ifndef SCI0_H_
#define SCI0_H_

//#define BAUD1 115200

void SCI0_Init(void);

void SCI0_Send(unsigned char);

unsigned char SCI0_Read(void);

// #pragma CODE_SEG __NEAR_SEG NON_BANKED

// void  interrupt 21 SCIbu0_re(void)

// #pragma CODE_SEG DEFAULT

#endif