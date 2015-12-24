/*
*********************************************************************************************************
*
*                                      MCU: MC9S12XS128MAL - 112Pin
*                                      OSC: 16.000MHz
*                                      BUS: 32.0MHz
*
*
* File : CCD.h
* By   : atao
*********************************************************************************************************
*/


#ifndef CCD_H_
#define CCD_H_

/* TSL1401_CLK -- PORTA0 */
#define TSL1401_CLK_DDR     DDRB_DDRB6
#define TSL1401_CLK         PORTB_PB6

/* TSL1401_SI -- PORTA1 */
#define TSL1401_SI_DDR      DDRB_DDRB7
#define TSL1401_SI          PORTB_PB7


void CalculateIntegrationTime(void);

unsigned char PixelAverage(unsigned char len, unsigned char *data);


unsigned char PixelMaxValue(unsigned char l, unsigned char r,
	unsigned char *data);


void PixelDifference(unsigned char *Image, unsigned char *Diff);
void StartIntegration(void);

void ImageCapture(unsigned char * ImageData);

void CCD_IO_Init(void);

void Get_Line(void);

extern unsigned char Pixel[128];

extern unsigned char PixelDiff[128];

extern unsigned char Line_L;

extern unsigned char Line_R;

extern unsigned char Line_L_Miss;

extern unsigned char Line_R_Miss;

extern unsigned char Middle_Line;

extern unsigned char Single_Line_Boot_Flag;


#endif /* #ifndef CCD_H_ */
