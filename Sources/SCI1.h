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

#ifndef SCI1_H_
#define SCI1_H_
 
//#define BAUD1 115200

void SCI1_Init(void);

void SCI1_Send(unsigned char);

unsigned char SCI1_Read(void);

// #pragma CODE_SEG __NEAR_SEG NON_BANKED

// void  interrupt 21 SCIbu0_re(void)

// #pragma CODE_SEG DEFAULT

#endif