/*
*********************************************************************************************************
*
*                                      MCU: MC9S12XS128MAL - 112Pin
*                                      OSC: 16.000MHz
*                                      BUS: 32.0MHz
*
* File : CPU.c
* By   : atao
*********************************************************************************************************
*/
#include "Include.h"
 
void Delay_us(int us)	//5.408uS	
{
	int i, j;
	for (i = 0; i<us; i++)
		for (j = 0; j<5; j++);
}

void Delay_ms(int ms)
{
	int i, j;
	for (i = 0; i<ms; i++)
	{
		for (j = 0; j<2770; j++);
	}
}
void SetBusCLK_16M(void)  
{     
    CLKSEL=0X00;    // disengage PLL to system  
    PLLCTL_PLLON=1; // turn on PLL  
    SYNR=0x00 | 0x01;   // VCOFRQ[7:6];SYNDIV[5:0]  
                        // fVCO= 2*fOSC*(SYNDIV + 1)/(REFDIV + 1)  
                        // fPLL= fVCO/(2 × POSTDIV)   
                        // fBUS= fPLL/2   
                        // VCOCLK Frequency Ranges  VCOFRQ[7:6]  
                        // 32MHz <= fVCO <= 48MHz    00  
                        // 48MHz <  fVCO <= 80MHz    01  
                        // Reserved                  10  
                        // 80MHz <  fVCO <= 120MHz   11                 
    REFDV=0x80 | 0x01;  // REFFRQ[7:6];REFDIV[5:0]  
                        // fREF=fOSC/(REFDIV + 1)  
                        // REFCLK Frequency Ranges  REFFRQ[7:6]  
                        // 1MHz <= fREF <=  2MHz       00  
                        // 2MHz <  fREF <=  6MHz       01  
                        // 6MHz <  fREF <= 12MHz       10  
                        // fREF >  12MHz               11                           
                        // pllclock=2*osc*(1+SYNR)/(1+REFDV)=32MHz;  
    POSTDIV=0x00;       // 4:0, fPLL= fVCO/(2xPOSTDIV)  
                        // If POSTDIV = $00 then fPLL is identical to fVCO (divide by one).  
    _asm(nop);          // BUS CLOCK=16M  
    _asm(nop);  
    while(!(CRGFLG_LOCK==1));     //when pll is steady ,then use it;  
    CLKSEL_PLLSEL =1;               //engage PLL to system;   
}  
  
void SetBusCLK_32M(void)  
{     
    CLKSEL=0X00;                // disengage PLL to system  
    PLLCTL_PLLON=1;         // turn on PLL  
    SYNR =0x40 | 0x03;  // pllclock=2*osc*(1+SYNR)/(1+REFDV)=64MHz;                        
    REFDV=0x80 | 0x01;   
    POSTDIV=0x00;    
    _asm(nop);          // BUS CLOCK=32M  
    _asm(nop);  
    while(!(CRGFLG_LOCK==1));     //when pll is steady ,then use it;  
    CLKSEL_PLLSEL =1;               //engage PLL to system;   
}  
  
void SetBusCLK_40M(void)  
{     
    CLKSEL=0X00;                //disengage PLL to system  
    PLLCTL_PLLON=1;         //turn on PLL  
    SYNR =0xc0 | 0x04;                          
    REFDV=0x80 | 0x01;   
    POSTDIV=0x00;       //pllclock=2*osc*(1+SYNR)/(1+REFDV)=80MHz;  
    _asm(nop);          //BUS CLOCK=40M  
    _asm(nop);  
    while(!(CRGFLG_LOCK==1));     //when pll is steady ,then use it;  
    CLKSEL_PLLSEL =1;               //engage PLL to system;   
}  
  
void SetBusCLK_48M(void)  
{     
    CLKSEL=0X00;                //disengage PLL to system  
    PLLCTL_PLLON=1;         //turn on PLL  
    SYNR =0xc0 | 0x05;                          
    REFDV=0x80 | 0x01;   
    POSTDIV=0x00;       //pllclock=2*osc*(1+SYNR)/(1+REFDV)=96MHz;  
    _asm(nop);          //BUS CLOCK=48M  
    _asm(nop);  
    while(!(CRGFLG_LOCK==1));     //when pll is steady ,then use it;  
    CLKSEL_PLLSEL =1;               //engage PLL to system;   
}  
  
void SetBusCLK_64M(void)  
{     
    CLKSEL=0X00;                //disengage PLL to system  
    PLLCTL_PLLON=1;         //turn on PLL  
    SYNR =0xc0 | 0x07;                          
    REFDV=0x80 | 0x01;   
    POSTDIV=0x00;       //pllclock=2*osc*(1+SYNR)/(1+REFDV)=128MHz;  
    _asm(nop);          //BUS CLOCK=64M  
    _asm(nop);  
    while(!(CRGFLG_LOCK==1));     //when pll is steady ,then use it;  
    CLKSEL_PLLSEL =1;               //engage PLL to system;   
}  
  
void SetBusCLK_80M(void)  
{     
    CLKSEL=0X00;                //disengage PLL to system  
    PLLCTL_PLLON=1;         //turn on PLL  
    SYNR =0xc0 | 0x09;                          
    REFDV=0x80 | 0x01;   
    POSTDIV=0x00;       //pllclock=2*osc*(1+SYNR)/(1+REFDV)=160MHz;  
    _asm(nop);          //BUS CLOCK=80M  
    _asm(nop);  
    while(!(CRGFLG_LOCK==1));     //when pll is steady ,then use it;  
    CLKSEL_PLLSEL =1;               //engage PLL to system;   
}  
                                                    
void SetBusCLK_88M(void)  
{     
    CLKSEL=0X00;                //disengage PLL to system  
    PLLCTL_PLLON=1;         //turn on PLL  
    SYNR =0xc0 | 0x0a;                          
    REFDV=0x80 | 0x01;   
    POSTDIV=0x00;       //pllclock=2*osc*(1+SYNR)/(1+REFDV)=176MHz;  
    _asm(nop);          //BUS CLOCK=88M  
    _asm(nop);  
    while(!(CRGFLG_LOCK==1));     //when pll is steady ,then use it;  
    CLKSEL_PLLSEL =1;               //engage PLL to system;   
}  
  
void SetBusCLK_96M(void)  
{     
    CLKSEL=0X00;                //disengage PLL to system  
    PLLCTL_PLLON=1;         //turn on PLL  
    SYNR =0xc0 | 0x0b;                          
    REFDV=0x80 | 0x01;   
    POSTDIV=0x00;       //pllclock=2*osc*(1+SYNR)/(1+REFDV)=192MHz;  
    _asm(nop);          //BUS CLOCK=96M  
    _asm(nop);  
    while(!(CRGFLG_LOCK==1));     //when pll is steady ,then use it;  
    CLKSEL_PLLSEL =1;               //engage PLL to system;   
}  
  
void SetBusCLK_104M(void)  
{     
    CLKSEL=0X00;                //disengage PLL to system  
    PLLCTL_PLLON=1;         //turn on PLL  
    SYNR =0xc0 | 0x0c;                          
    REFDV=0x80 | 0x01;   
    POSTDIV=0x00;       //pllclock=2*osc*(1+SYNR)/(1+REFDV)=208MHz;  
    _asm(nop);          //BUS CLOCK=104M  
    _asm(nop);  
    while(!(CRGFLG_LOCK==1));     //when pll is steady ,then use it;  
    CLKSEL_PLLSEL =1;               //engage PLL to system;   
}  
  
void SetBusCLK_120M(void)  
{     
    CLKSEL=0X00;                //disengage PLL to system  
    PLLCTL_PLLON=1;         //turn on PLL  
    SYNR =0xc0 | 0x0d;                          
    REFDV=0x80 | 0x01;   
    POSTDIV=0x00;       //pllclock=2*osc*(1+SYNR)/(1+REFDV)=240MHz;  
    _asm(nop);          //BUS CLOCK=120M  
    _asm(nop);  
    while(!(CRGFLG_LOCK==1));     //when pll is steady ,then use it;  
    CLKSEL_PLLSEL =1;               //engage PLL to system;   
}  
