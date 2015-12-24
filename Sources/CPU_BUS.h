/*
*********************************************************************************************************
*
*                                      MCU: MC9S12XS128MAL - 112Pin
*                                      OSC: 16.000MHz
*                                      BUS: 32.0MHz
*
* File : CPU.h
* By   : atao
*********************************************************************************************************
*/
#ifndef   CPU_BUS_H_
#define	  CPU_BUS_H_

#define BUS_FREQ 64000000





 #pragma LINK_INFO DERIVATIVE "mc9s12xs128"



/* CPU delay 1us at 40M bus clock */\
#define Cpu_Delay1us() \
    { __asm(nop); __asm(nop); __asm(nop); __asm(nop);\
      __asm(nop); __asm(nop); __asm(nop); __asm(nop);\
      __asm(nop); __asm(nop); __asm(nop); __asm(nop);\
      __asm(nop); __asm(nop); __asm(nop); __asm(nop);\
      __asm(nop); __asm(nop); __asm(nop); __asm(nop);\
      __asm(nop); __asm(nop); __asm(nop); __asm(nop);\
      __asm(nop); __asm(nop); __asm(nop); __asm(nop);\
      __asm(nop); __asm(nop); __asm(nop); __asm(nop);\
      __asm(nop); __asm(nop); __asm(nop); __asm(nop);\
      __asm(nop); __asm(nop); __asm(nop); __asm(nop);\
    }

/* CPU delay 200ns at 40M bus clock */\
#define Cpu_Delay200ns() \
    { __asm(nop); __asm(nop); __asm(nop); __asm(nop);\
      __asm(nop); __asm(nop); __asm(nop); __asm(nop);}

#define SamplingDelay() \
		Cpu_Delay200ns()

void Delay_us(int us);

void Delay_ms(int ms);

void SetBusCLK_16M(void);

void SetBusCLK_32M(void);

void SetBusCLK_40M(void);

void SetBusCLK_48M(void);

void SetBusCLK_64M(void);

void SetBusCLK_80M(void);

void SetBusCLK_88M(void);

void SetBusCLK_96M(void);

void SetBusCLK_104M(void);

void SetBusCLK_120M(void);



#endif
