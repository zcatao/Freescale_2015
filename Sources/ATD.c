/*
*********************************************************************************************************
*
*                                      MCU: MC9S12XS128MAL - 112Pin
*                                      OSC: 16.000MHz
*                                      BUS: 32.0MHz
*                 Describe: ATD0 八路
*                 
* File : ATD.c
* By   : atao
*********************************************************************************************************
*/
#include "Include.h"

void ATD0_Init(void) 
{  
  ATD0CTL1=0x40;   //7:1-å¤–éƒ¨è§¦å‘,65:00-8ä½ç²¾åº¦,4:æ”¾ç”µ,3210:ch
  ATD0CTL2=0x40;   //ç¦æ­¢å¤–éƒ¨è§¦å‘, ä¸­æ–­ç¦æ­¢    
  ATD0CTL3=0x80;   //å³å¯¹é½æ— ç¬¦å·,æ¯æ¬¡è½¬æ¢8ä¸ªåºåˆ—, No FIFO, Freezeæ¨¡å¼ä¸‹ç»§ç»­è½¬        
  ATD0CTL4=0x01;   //765:é‡‡æ ·æ—¶é—´ä¸º4ä¸ªADæ—¶é’Ÿå‘ ¨æœŸ,ATDClock=[BusClock*0.5]/[PRS+1]
  ATD0CTL5=0x30;   //6:0ç‰¹æ®Šé€šé“ç¦æ­¢,5:1è¿žç»­è½¬æ¢ ,4:1å¤šé€šé“è½®æµé‡‡æ ·
  ATD0DIEN=0x00;   //ç¦æ­¢æ•°å­—è¾“å…¥ 
  
} 
unsigned int ATD0_Read(unsigned char ch)
{
  unsigned int ad = 0;
  while(!ATD0STAT0_SCF);
  switch(ch)
  {
    default:
    case 0:
		ad = ATD0DR0;
		break;
    case 1:
		ad = ATD0DR1;
	  break;
    case 2:
		ad = ATD0DR2;
		break;
    case 3:
		ad = ATD0DR3;
		break;
    case 4:
		ad = ATD0DR4;
		break;
    case 5:
		ad = ATD0DR5;
		break;
    case 6:
		ad = ATD0DR6;
		break;
    case 7:
		ad = ATD0DR7;
		break;
	case 8:
		ad = ATD0DR8;
		break;
	case 9 :
		ad = ATD0DR9;
		break;
	case 10:
		ad = ATD0DR10;
		break;
	case 11:
		ad = ATD0DR11;
		break;
	case 12:
		ad = ATD0DR12;
		break;
	case 13:
		ad = ATD0DR13;
		break;
	case 14:
		ad = ATD0DR14;
		break;
	case 15:
		ad = ATD0DR15;
		break;
	
  }
  return ad;
}