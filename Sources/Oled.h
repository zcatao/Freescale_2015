#ifndef _oled_H
#define _oled_H

#ifndef	uchar
#define uchar unsigned char
#endif

#ifndef uint
#define uint unsigned int
#endif

#define LED_SCL       PORTB_PB0
#define LED_SDA       PORTB_PB1
#define LED_RST       PORTB_PB2
#define LED_DC        PORTB_PB3
#define LED_PORT      DDRB

void oled_Init(void);
void LED_SetPos(uchar ucIdxX, uchar ucIdxY);
void LED_WrDat(uchar ucData);
void LED_P6x8Valuef(uchar ucIdxX,uchar ucIdxY , float Data);
void LED_P6x8Value4(uchar ucIdxX,uchar ucIdxY , uint Data);
void LED_P6x8Value_signed(uchar ucIdxX, uchar ucIdxY,int Data);
void LED_P6x8Value(uchar ucIdxX, uchar ucIdxY,uint Data);
void LED_P6x8Str(uchar ucIdxX, uchar ucIdxY, uchar ucDataStr[]);

#endif
