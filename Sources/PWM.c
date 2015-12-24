/*
*********************************************************************************************************
*
*                                      MCU: MC9S12XS128MAL - 112Pin
*                                      OSC: 16.000MHz
*                                      BUS: 32.0MHz
*
* File : PWM.c
* By   : atao
*********************************************************************************************************
*/

#include "Include.h"

void PWM_Init() {
                                       
  PWMPRCLK = PWM_PRCLK;                //PWMÃƒâ€Ã‚Â¤Ã‚Â·Ãƒâ€“Ãƒâ€ Ã‚ÂµÃƒÅ Ã‚Â±Ãƒâ€“Ãƒâ€œÃƒâ€˜Ã‚Â¡Ãƒâ€ÃƒÂ±Ã‚Â¼Ãƒâ€žÃ‚Â´ÃƒÂ¦Ãƒâ€ ÃƒÂ·
  PWMSCLA = CH_SA_DIV;                 //PWMÃ‚Â±ÃƒË†Ãƒâ‚¬ÃƒÂ½Ãƒâ€™ÃƒÂ²Ãƒâ€”Ãƒâ€œÃ‚Â¼Ãƒâ€žÃ‚Â´ÃƒÂ¦Ãƒâ€ ÃƒÂ·Ã‚Â£Ã‚Â¬Ã‚Â¶Ãƒâ€SAÃ‚Â½ÃƒÂ¸ÃƒÂÃƒÂÃ‚Â·Ãƒâ€“Ãƒâ€ Ã‚Âµ
  PWMSCLB = CH_SB_DIV;
  
  PWMCLK_PCLK0 = 1;                    //PWM0ÃƒÅ Ã‚Â¹Ãƒâ€œÃƒÆ’SAÃƒÅ Ã‚Â±Ãƒâ€“Ãƒâ€œ
  PWMCLK_PCLK1 = 1;                    //PWM1ÃƒÅ Ã‚Â¹Ãƒâ€œÃƒÆ’SAÃƒÅ Ã‚Â±Ãƒâ€“Ãƒâ€œ
  PWMCLK_PCLK6 = 1;                    //PWM6ÃƒÅ Ã‚Â¹Ãƒâ€œÃƒÆ’SBÃƒÅ Ã‚Â±Ãƒâ€“Ãƒâ€œ
  PWMCLK_PCLK7 = 1;                    //PWM7ÃƒÅ Ã‚Â¹Ãƒâ€œÃƒÆ’SBÃƒÅ Ã‚Â±Ãƒâ€“Ãƒâ€œ
  
  PWMPER0 = (CH_SA_FREQ / Motor_FREQ); //ÃƒÂÃ‚Â´PWM0Ã‚ÂµÃƒâ€žÃƒâ€“ÃƒÅ“Ãƒâ€ ÃƒÅ¡Ã‚Â¼Ãƒâ€žÃ‚Â´ÃƒÂ¦Ãƒâ€ ÃƒÂ· = 200
  PWMPER1 = (CH_SA_FREQ / Motor_FREQ);
  PWMPER6 = (CH_SA_FREQ / Motor_FREQ);
  PWMPER7 = (CH_SB_FREQ / Motor_FREQ);
                                       
  PWMPOL_PPOL1 = 1;                    //Ã‚Â¼Ã‚Â«ÃƒÂÃƒâ€ÃƒÂÃƒÂ Ã‚Â·Ã‚Â´ 
  PWMPOL_PPOL0 = 1;
  PWMPOL_PPOL6 = 1;                      
  PWMPOL_PPOL7 = 1;
    
  PWMCAE = 0X00;                        //Ãƒâ€”ÃƒÂ³Ã‚Â¶Ãƒâ€Ãƒâ€ ÃƒÂ«
}

void Motor_back_1(uchar duty) {
  PWMDTY0 = duty;
  PWME_PWME1 = 0;                       //Ã‚Â½ÃƒÂ»Ãƒâ€“Ã‚Â¹ÃƒÅ Ã‚Â¹Ãƒâ€žÃƒÅ“IN2
  PWME_PWME0 = 1;                       //ÃƒÅ Ã‚Â¹Ãƒâ€žÃƒÅ“IN1
  DDRP_DDRP1 = 1;                       //PTP_PTP1 ÃƒÅ½Ã‚ÂªÃƒÅ ÃƒÂ¤Ã‚Â³ÃƒÂ¶
  PTP_PTP1 = 0;
  DDRK_DDRK4 = 1;
  PORTK_PK4 = 1;
}

void Motor_back_0(uchar duty) {
  PWMDTY6 = duty;
  PWME_PWME7 = 0;                       //Ã‚Â½ÃƒÂ»Ãƒâ€“Ã‚Â¹ÃƒÅ Ã‚Â¹Ãƒâ€žÃƒÅ“IN2
  PWME_PWME6 = 1;                       //ÃƒÅ Ã‚Â¹Ãƒâ€žÃƒÅ“IN1
  DDRP_DDRP7 = 1;                       //PTP_PTP1 ÃƒÅ½Ã‚ÂªÃƒÅ ÃƒÂ¤Ã‚Â³ÃƒÂ¶
  PTP_PTP7 = 0;
}

void Motor_forward_1(uchar duty) {
  PWMDTY1 = duty;
  PWME_PWME0 = 0;
  PWME_PWME1 = 1;
  DDRP_DDRP0 = 1;
  PTP_PTP0 = 0;
}

void Motor_forward_0(uchar duty) {
  PWMDTY7= duty;
  PWME_PWME6 = 0;
  PWME_PWME7 = 1;
  DDRP_DDRP6 = 1;
  PTP_PTP6 = 0;
}

void Motor_brake() {
  PWME_PWME0 = 0;                      //Ã‚Â½ÃƒÂ»Ãƒâ€“Ã‚Â¹ÃƒÅ’ÃƒËœÃƒÅ ÃƒÂ¢Ã‚Â¹Ã‚Â¦Ãƒâ€žÃƒÅ“
  PWME_PWME1 = 0;
  PWME_PWME6 = 0;
  PWME_PWME7 = 0;
  DDRP_DDRP7 = 1;                      //Ã‚Â¶Ãƒâ€¹Ã‚Â¿ÃƒÅ¡ÃƒÅ½Ã‚ÂªÃƒÅ ÃƒÂ¤Ã‚Â³ÃƒÂ¶
  DDRP_DDRP6 = 1;
  DDRP_DDRP1 = 1;
  DDRP_DDRP0 = 1;
  PTP_PTP0 = 0;                        //Ã‚Â¶Ãƒâ€¹Ã‚Â¿ÃƒÅ¡ÃƒÅ ÃƒÂ¤Ã‚Â³ÃƒÂ¶ÃƒÅ½Ã‚Âª0
  PTP_PTP1 = 0;
  PTP_PTP6 = 0;
  PTP_PTP7 = 0;
}
