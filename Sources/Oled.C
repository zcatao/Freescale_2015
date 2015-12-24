
#include "include.h"



const uchar F6x8[][6] =
{
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },   //sp0
    { 0x00, 0x00, 0x00, 0x2f, 0x00, 0x00 },   // !1
    { 0x00, 0x00, 0x07, 0x00, 0x07, 0x00 },   // "2
    { 0x00, 0x14, 0x7f, 0x14, 0x7f, 0x14 },   // #3
    { 0x00, 0x24, 0x2a, 0x7f, 0x2a, 0x12 },   // $4
    { 0x00, 0x62, 0x64, 0x08, 0x13, 0x23 },   // %5
    { 0x00, 0x36, 0x49, 0x55, 0x22, 0x50 },   // &6
    { 0x00, 0x00, 0x05, 0x03, 0x00, 0x00 },   // '7
    { 0x00, 0x00, 0x1c, 0x22, 0x41, 0x00 },   // (8
    { 0x00, 0x00, 0x41, 0x22, 0x1c, 0x00 },   // )9
    { 0x00, 0x14, 0x08, 0x3E, 0x08, 0x14 },   // *10
    { 0x00, 0x08, 0x08, 0x3E, 0x08, 0x08 },   // +11
    { 0x00, 0x00, 0x00, 0xA0, 0x60, 0x00 },   // ,12
    { 0x00, 0x08, 0x08, 0x08, 0x08, 0x08 },   // -13
    { 0x00, 0x00, 0x60, 0x60, 0x00, 0x00 },   // .14
    { 0x00, 0x20, 0x10, 0x08, 0x04, 0x02 },   // /15
    { 0x00, 0x3E, 0x51, 0x49, 0x45, 0x3E },   // 016
    { 0x00, 0x00, 0x42, 0x7F, 0x40, 0x00 },   // 117
    { 0x00, 0x42, 0x61, 0x51, 0x49, 0x46 },   // 218
    { 0x00, 0x21, 0x41, 0x45, 0x4B, 0x31 },   // 319
    { 0x00, 0x18, 0x14, 0x12, 0x7F, 0x10 },   // 420
    { 0x00, 0x27, 0x45, 0x45, 0x45, 0x39 },   // 521
    { 0x00, 0x3C, 0x4A, 0x49, 0x49, 0x30 },   // 622
    { 0x00, 0x01, 0x71, 0x09, 0x05, 0x03 },   // 723
    { 0x00, 0x36, 0x49, 0x49, 0x49, 0x36 },   // 824
    { 0x00, 0x06, 0x49, 0x49, 0x29, 0x1E },   // 925
    { 0x00, 0x00, 0x36, 0x36, 0x00, 0x00 },   // :26
    { 0x00, 0x00, 0x56, 0x36, 0x00, 0x00 },   // ;27
    { 0x00, 0x08, 0x14, 0x22, 0x41, 0x00 },   // <28
    { 0x00, 0x14, 0x14, 0x14, 0x14, 0x14 },   // =29
    { 0x00, 0x00, 0x41, 0x22, 0x14, 0x08 },   // >30
    { 0x00, 0x02, 0x01, 0x51, 0x09, 0x06 },   // ?31
    { 0x00, 0x32, 0x49, 0x59, 0x51, 0x3E },   // @32
    { 0x00, 0x7C, 0x12, 0x11, 0x12, 0x7C },   // A33
    { 0x00, 0x7F, 0x49, 0x49, 0x49, 0x36 },   // B34
    { 0x00, 0x3E, 0x41, 0x41, 0x41, 0x22 },   // C35
    { 0x00, 0x7F, 0x41, 0x41, 0x22, 0x1C },   // D36
    { 0x00, 0x7F, 0x49, 0x49, 0x49, 0x41 },   // E37
    { 0x00, 0x7F, 0x09, 0x09, 0x09, 0x01 },   // F38
    { 0x00, 0x3E, 0x41, 0x49, 0x49, 0x7A },   // G39
    { 0x00, 0x7F, 0x08, 0x08, 0x08, 0x7F },   // H40
    { 0x00, 0x00, 0x41, 0x7F, 0x41, 0x00 },   // I41
    { 0x00, 0x20, 0x40, 0x41, 0x3F, 0x01 },   // J42
    { 0x00, 0x7F, 0x08, 0x14, 0x22, 0x41 },   // K43
    { 0x00, 0x7F, 0x40, 0x40, 0x40, 0x40 },   // L44
    { 0x00, 0x7F, 0x02, 0x0C, 0x02, 0x7F },   // M45
    { 0x00, 0x7F, 0x04, 0x08, 0x10, 0x7F },   // N46
    { 0x00, 0x3E, 0x41, 0x41, 0x41, 0x3E },   // O47
    { 0x00, 0x7F, 0x09, 0x09, 0x09, 0x06 },   // P48
    { 0x00, 0x3E, 0x41, 0x51, 0x21, 0x5E },   // Q49
    { 0x00, 0x7F, 0x09, 0x19, 0x29, 0x46 },   // R50
    { 0x00, 0x46, 0x49, 0x49, 0x49, 0x31 },   // S51
    { 0x00, 0x01, 0x01, 0x7F, 0x01, 0x01 },   // T52
    { 0x00, 0x3F, 0x40, 0x40, 0x40, 0x3F },   // U53
    { 0x00, 0x1F, 0x20, 0x40, 0x20, 0x1F },   // V54
    { 0x00, 0x3F, 0x40, 0x38, 0x40, 0x3F },   // W55
    { 0x00, 0x63, 0x14, 0x08, 0x14, 0x63 },   // X56
    { 0x00, 0x07, 0x08, 0x70, 0x08, 0x07 },   // Y57
    { 0x00, 0x61, 0x51, 0x49, 0x45, 0x43 },   // Z58
    { 0x00, 0x00, 0x7F, 0x41, 0x41, 0x00 },   // [59
    { 0x00, 0x02, 0x04, 0x08, 0x10, 0x20 },   // \60
    { 0x00, 0x00, 0x41, 0x41, 0x7F, 0x00 },   // ]61
    { 0x00, 0x04, 0x02, 0x01, 0x02, 0x04 },   // ^62
    { 0x00, 0x40, 0x40, 0x40, 0x40, 0x40 },   // _63
    { 0x00, 0x00, 0x01, 0x02, 0x04, 0x00 },   // '64
    { 0x00, 0x20, 0x54, 0x54, 0x54, 0x78 },   // a65
    { 0x00, 0x7F, 0x48, 0x44, 0x44, 0x38 },   // b66
    { 0x00, 0x38, 0x44, 0x44, 0x44, 0x20 },   // c67
    { 0x00, 0x38, 0x44, 0x44, 0x48, 0x7F },   // d68
    { 0x00, 0x38, 0x54, 0x54, 0x54, 0x18 },   // e69
    { 0x00, 0x08, 0x7E, 0x09, 0x01, 0x02 },   // f70
    { 0x00, 0x18, 0xA4, 0xA4, 0xA4, 0x7C },   // g71
    { 0x00, 0x7F, 0x08, 0x04, 0x04, 0x78 },   // h72
    { 0x00, 0x00, 0x44, 0x7D, 0x40, 0x00 },   // i73
    { 0x00, 0x40, 0x80, 0x84, 0x7D, 0x00 },   // j74
    { 0x00, 0x7F, 0x10, 0x28, 0x44, 0x00 },   // k75
    { 0x00, 0x00, 0x41, 0x7F, 0x40, 0x00 },   // l76
    { 0x00, 0x7C, 0x04, 0x18, 0x04, 0x78 },   // m77
    { 0x00, 0x7C, 0x08, 0x04, 0x04, 0x78 },   // n78
    { 0x00, 0x38, 0x44, 0x44, 0x44, 0x38 },   // o79
    { 0x00, 0xFC, 0x24, 0x24, 0x24, 0x18 },   // p80
    { 0x00, 0x18, 0x24, 0x24, 0x18, 0xFC },   // q81
    { 0x00, 0x7C, 0x08, 0x04, 0x04, 0x08 },   // r82
    { 0x00, 0x48, 0x54, 0x54, 0x54, 0x20 },   // s83
    { 0x00, 0x04, 0x3F, 0x44, 0x40, 0x20 },   // t84
    { 0x00, 0x3C, 0x40, 0x40, 0x20, 0x7C },   // u85
    { 0x00, 0x1C, 0x20, 0x40, 0x20, 0x1C },   // v86
    { 0x00, 0x3C, 0x40, 0x30, 0x40, 0x3C },   // w87
    { 0x00, 0x44, 0x28, 0x10, 0x28, 0x44 },   // x88
    { 0x00, 0x1C, 0xA0, 0xA0, 0xA0, 0x7C },   // y89
    { 0x00, 0x44, 0x64, 0x54, 0x4C, 0x44 },   // z90
    { 0x14, 0x14, 0x14, 0x14, 0x14, 0x14 }    // horiz lines91
};


/*****************************************************************************
 Ã‚ÂºÃ‚Â¯ ÃƒÅ ÃƒÂ½ ÃƒÆ’ÃƒÂ»  : LED_WrDat
 Ã‚Â¹Ã‚Â¦Ãƒâ€žÃƒÅ“ÃƒÆ’ÃƒÂ¨ÃƒÅ ÃƒÂ¶  : ÃƒÂÃƒÂ²OLEDÃƒÂÃ‚Â´ÃƒÅ ÃƒÂ½Ã‚Â¾ÃƒÂ
 ÃƒÅ ÃƒÂ¤ÃƒË†ÃƒÂ«Ã‚Â²ÃƒÅ½ÃƒÅ ÃƒÂ½  : UCHAR8 ucData
 ÃƒÅ ÃƒÂ¤Ã‚Â³ÃƒÂ¶Ã‚Â²ÃƒÅ½ÃƒÅ ÃƒÂ½  : NONE
 Ã‚Â·Ã‚Âµ Ã‚Â»ÃƒËœ Ãƒâ€“Ã‚Âµ  : NONE
*****************************************************************************/
void LED_WrDat(uchar ucData)
{
    uchar i = 8;
    LED_DC   = 1;
    LED_SCL  = 0;

    while (i--)
    {
        if (ucData & 0x80)
        {
            LED_SDA = 1;
        }
        else
        {
            LED_SDA = 0;
        }
        LED_SCL = 1;
        asm("nop");
        LED_SCL = 0;
        ucData <<= 1;
    }

    return;
}

/*****************************************************************************
 Ã‚ÂºÃ‚Â¯ ÃƒÅ ÃƒÂ½ ÃƒÆ’ÃƒÂ»  : LED_WrCmd
 Ã‚Â¹Ã‚Â¦Ãƒâ€žÃƒÅ“ÃƒÆ’ÃƒÂ¨ÃƒÅ ÃƒÂ¶  : ÃƒÂÃƒÂ²OLEDÃƒÂÃ‚Â´ÃƒÆ’ÃƒÂ¼ÃƒÂÃƒÂ®
 ÃƒÅ ÃƒÂ¤ÃƒË†ÃƒÂ«Ã‚Â²ÃƒÅ½ÃƒÅ ÃƒÂ½  : UCHAR8 ucCmd
 ÃƒÅ ÃƒÂ¤Ã‚Â³ÃƒÂ¶Ã‚Â²ÃƒÅ½ÃƒÅ ÃƒÂ½  : NONE
 Ã‚Â·Ã‚Âµ Ã‚Â»ÃƒËœ Ãƒâ€“Ã‚Âµ  : NONE
*****************************************************************************/
void LED_WrCmd(uchar ucCmd)
{
    uchar i = 8;
    LED_DC   = 0;
    LED_SCL  = 0;
    while (i--)
    {
        if (ucCmd & 0x80)   //1000 0000
        {
            LED_SDA = 1;
        }
        else
        {
            LED_SDA = 0;
        }
        LED_SCL = 1;
        asm("nop");
        LED_SCL = 0;
        ucCmd <<= 1; //0010 0000   0x20
    }

    return;
}
/*****************************************************************************
 Ã‚ÂºÃ‚Â¯ ÃƒÅ ÃƒÂ½ ÃƒÆ’ÃƒÂ»  : LED_SetPos
 Ã‚Â¹Ã‚Â¦Ãƒâ€žÃƒÅ“ÃƒÆ’ÃƒÂ¨ÃƒÅ ÃƒÂ¶  : Ãƒâ€°ÃƒÂ¨Ãƒâ€“ÃƒÆ’Ãƒâ€”ÃƒÂ¸Ã‚Â±ÃƒÂª
 ÃƒÅ ÃƒÂ¤ÃƒË†ÃƒÂ«Ã‚Â²ÃƒÅ½ÃƒÅ ÃƒÂ½  : UCHAR8 ucIdxX
             UCHAR8 ucIdxY
 ÃƒÅ ÃƒÂ¤Ã‚Â³ÃƒÂ¶Ã‚Â²ÃƒÅ½ÃƒÅ ÃƒÂ½  : NONE
 Ã‚Â·Ã‚Âµ Ã‚Â»ÃƒËœ Ãƒâ€“Ã‚Âµ  : NONE
*****************************************************************************/
void LED_SetPos(uchar ucIdxX, uchar ucIdxY)
{
    LED_WrCmd(0xb0 + ucIdxY);
    LED_WrCmd(((ucIdxX & 0xf0) >> 4) | 0x10);
    LED_WrCmd((ucIdxX & 0x0f) | 0x00);
}

/*****************************************************************************
 Ã‚ÂºÃ‚Â¯ ÃƒÅ ÃƒÂ½ ÃƒÆ’ÃƒÂ»  : LED_Fill
 Ã‚Â¹Ã‚Â¦Ãƒâ€žÃƒÅ“ÃƒÆ’ÃƒÂ¨ÃƒÅ ÃƒÂ¶  : Ã‚Â¶Ãƒâ€ÃƒË†Ã‚Â«Ãƒâ€ ÃƒÂÃƒÂÃ‚Â´ÃƒË†ÃƒÂ«ÃƒÂÃ‚Â¬Ãƒâ€™Ã‚Â»Ã‚Â¸ÃƒÂ¶Ãƒâ€”Ãƒâ€“Ã‚Â·ÃƒÂ»Ã‚ÂºÃ‚Â¯ÃƒÅ ÃƒÂ½
             ÃƒË†ÃƒÂ§ LED_Fill(0x01);    Ã‚Â¶Ãƒâ€Ãƒâ€œÃƒÅ¡Ãƒâ€žÃ‚Â³Ãƒâ€™Ã‚Â»ÃƒÅ½Ã‚Â»0ÃƒÅ½Ã‚ÂªÃ‚Â²Ã‚Â»ÃƒÂÃƒÂ 1ÃƒÅ½Ã‚ÂªÃƒÂÃƒÂ
            ------------------------------------------------------
                                Ã‚Â¹Ã‚Â²128ÃƒÂÃƒÂ
                  1           1                1
              Ã‚Â¹Ã‚Â²  0           0                0
              8   0           0                0
              Ãƒâ€”ÃƒÂ©  0       Ã‚Â¡Ã‚Â­Ã‚Â¡Ã‚Â­0     Ã‚Â¡Ã‚Â­Ã‚Â¡Ã‚Â­Ã‚Â¡Ã‚Â­Ã‚Â¡Ã‚Â­   0
              Ãƒâ€”Ãƒâ€“  0           0                0
              Ã‚Â·ÃƒÂ»  0           0                0
              Ã‚Â¼Ã‚Â´  0           0                0
              8   0           0                0
              Ãƒâ€™Ã‚Â³  1           1                1
              64  0           0                0
              ÃƒÂÃƒÂ  .           .                .
                  .           .    Ã‚Â¡Ã‚Â­Ã‚Â¡Ã‚Â­Ã‚Â¡Ã‚Â­Ã‚Â¡Ã‚Â­    .
                  .           .                .
                  .           .                .
                  0           0                0
            ------------------------------------------------------
 ÃƒÅ ÃƒÂ¤ÃƒË†ÃƒÂ«Ã‚Â²ÃƒÅ½ÃƒÅ ÃƒÂ½  : UCHAR8 ucData
 ÃƒÅ ÃƒÂ¤Ã‚Â³ÃƒÂ¶Ã‚Â²ÃƒÅ½ÃƒÅ ÃƒÂ½  : NONE
 Ã‚Â·Ã‚Âµ Ã‚Â»ÃƒËœ Ãƒâ€“Ã‚Âµ  : NONE
*****************************************************************************/
void LED_Fill(uchar ucData)
{
    uchar ucPage,ucColumn;

    for(ucPage = 0; ucPage < 8; ucPage++)
    {
        LED_WrCmd(0xb0 + ucPage);  //0xb0+0~7Ã‚Â±ÃƒÂ­ÃƒÅ Ã‚Â¾Ãƒâ€™Ã‚Â³0~7

        for(ucColumn = 0; ucColumn < 128; ucColumn++)
        {
            LED_WrDat(ucData);
        }
    }
}

void SetDisplayOnOff(uchar ucData)
{
    LED_WrCmd(0xAE|ucData); // Set Display On/Off
                            // Default => 0xAE
                            // 0xAE (0x00) => Display Off
                            // 0xAF (0x01) => Display On
}
void SetChargePump(uchar ucData)
{
    LED_WrCmd(0x8D);        // Set Charge Pump
    LED_WrCmd(0x10|ucData); // Default => 0x10
                            // 0x10 (0x00) => Disable Charge Pump
                            // 0x14 (0x04) => Enable Charge Pump
}


void SetAddressingMode(uchar ucData)
{
    LED_WrCmd(0x20);        // Set Memory Addressing Mode
    LED_WrCmd(ucData);      // Default => 0x02
                            // 0x00 => Horizontal Addressing Mode
                            // 0x01 => Vertical Addressing Mode
                            // 0x02 => Page Addressing Mode
}

void SetSegmentRemap(uchar ucData)
{
    LED_WrCmd(0xA0|ucData); // Set Segment Re-Map
                            // Default => 0xA0
                            // 0xA0 (0x00) => Column Address 0 Mapped to SEG0
                            // 0xA1 (0x01) => Column Address 0 Mapped to SEG127
}

void SetCommonRemap(uchar ucData)
{
    LED_WrCmd(0xC0|ucData); // Set COM Output Scan Direction
                            // Default => 0xC0
                            // 0xC0 (0x00) => Scan from COM0 to 63
                            // 0xC8 (0x08) => Scan from COM63 to 0
}

void SetContrastControl(uchar ucData)
{
    LED_WrCmd(0x81);        // Set Contrast Control
    LED_WrCmd(ucData);      // Default => 0x7F
}

void SetInverseDisplay(uchar ucData)
{
    LED_WrCmd(0xA6|ucData); // Set Inverse Display On/Off
                            // Default => 0xA6
                            // 0xA6 (0x00) => Normal Display
                            // 0xA7 (0x01) => Inverse Display On
}

/*****************************************************************************
 Ã‚ÂºÃ‚Â¯ ÃƒÅ ÃƒÂ½ ÃƒÆ’ÃƒÂ»  : LED_Init
 Ã‚Â¹Ã‚Â¦Ãƒâ€žÃƒÅ“ÃƒÆ’ÃƒÂ¨ÃƒÅ ÃƒÂ¶  : OLEDÃ‚Â³ÃƒÂµÃƒÅ Ã‚Â¼Ã‚Â»Ã‚Â¯
 ÃƒÅ ÃƒÂ¤ÃƒË†ÃƒÂ«Ã‚Â²ÃƒÅ½ÃƒÅ ÃƒÂ½  : VOID
 ÃƒÅ ÃƒÂ¤Ã‚Â³ÃƒÂ¶Ã‚Â²ÃƒÅ½ÃƒÅ ÃƒÂ½  : NONE
 Ã‚Â·Ã‚Âµ Ã‚Â»ÃƒËœ Ãƒâ€“Ã‚Âµ  : NONE
*****************************************************************************/
void oled_Init(void)
{
    unsigned char i;
    LED_PORT=0x1f;  //0000 1111
    LED_SCL=1;
    LED_RST=0;
    for(i=0;i<100;i++)
    {
        asm("nop");            //Ã‚Â´Ãƒâ€œÃƒâ€°ÃƒÂÃ‚ÂµÃƒÂ§Ã‚ÂµÃ‚Â½ÃƒÂÃƒâ€šÃƒÆ’ÃƒÂ¦Ã‚Â¿Ã‚ÂªÃƒÅ Ã‚Â¼Ã‚Â³ÃƒÂµÃƒÅ Ã‚Â¼Ã‚Â»Ã‚Â¯Ãƒâ€™Ã‚ÂªÃƒâ€œÃƒÂÃƒâ€”ÃƒÂ£Ã‚Â¹Ã‚Â»Ã‚ÂµÃƒâ€žÃƒÅ Ã‚Â±Ã‚Â¼ÃƒÂ¤Ã‚Â£Ã‚Â¬Ã‚Â¼Ã‚Â´Ã‚ÂµÃƒË†Ã‚Â´ÃƒÂ½RCÃ‚Â¸Ã‚Â´ÃƒÅ½Ã‚Â»ÃƒÂÃƒÂªÃ‚Â±ÃƒÂ
    }

    LED_RST=1;

    SetDisplayOnOff(0x00);     // Display Off (0x00/0x01)
    SetChargePump(0x04);       // Enable Embedded DC/DC Converter (0x00/0x04)
    //SetAddressingMode(0x02);   // Set Page Addressing Mode (0x00/0x01/0x02)
    SetSegmentRemap(0x01);     // Set SEG/Column Mapping     0x00Ãƒâ€”ÃƒÂ³Ãƒâ€œÃƒâ€™Ã‚Â·Ã‚Â´Ãƒâ€“ÃƒÆ’ 0x01Ãƒâ€¢ÃƒÂ½Ã‚Â³Ã‚Â£
    SetCommonRemap(0x08);      // Set COM/Row Scan Direction 0x00Ãƒâ€°ÃƒÂÃƒÂÃƒâ€šÃ‚Â·Ã‚Â´Ãƒâ€“ÃƒÆ’ 0x08Ãƒâ€¢ÃƒÂ½Ã‚Â³Ã‚Â£
    SetContrastControl(0xCF);  // Set SEG Output Current
    SetInverseDisplay(0x00);   // Disable Inverse Display On (0x00/0x01)
    SetDisplayOnOff(0x01);     // Display On (0x00/0x01)
    LED_Fill(0x00);            // Ã‚Â³ÃƒÂµÃƒÅ Ã‚Â¼Ãƒâ€¡ÃƒÂ¥Ãƒâ€ ÃƒÂ
    LED_SetPos(0,0);

    return;
}

/*****************************************************************************
 Ã‚ÂºÃ‚Â¯ ÃƒÅ ÃƒÂ½ ÃƒÆ’ÃƒÂ»  : LED_P6x8Char
 Ã‚Â¹Ã‚Â¦Ãƒâ€žÃƒÅ“ÃƒÆ’ÃƒÂ¨ÃƒÅ ÃƒÂ¶  : ÃƒÂÃƒâ€ÃƒÅ Ã‚Â¾Ãƒâ€™Ã‚Â»Ã‚Â¸ÃƒÂ¶6x8Ã‚Â±ÃƒÂªÃƒâ€”Ã‚Â¼ASCIIÃƒâ€”Ãƒâ€“Ã‚Â·ÃƒÂ»
 ÃƒÅ ÃƒÂ¤ÃƒË†ÃƒÂ«Ã‚Â²ÃƒÅ½ÃƒÅ ÃƒÂ½  : UCHAR8 ucIdxX  ÃƒÂÃƒâ€ÃƒÅ Ã‚Â¾Ã‚ÂµÃƒâ€žÃ‚ÂºÃƒÂ¡Ãƒâ€”ÃƒÂ¸Ã‚Â±ÃƒÂª0~122
             UCHAR8 ucIdxY  Ãƒâ€™Ã‚Â³Ã‚Â·Ã‚Â¶ÃƒÅ½Ã‚Â§0Ã‚Â¡Ã‚Â«7
             UCHAR8 ucData  ÃƒÂÃƒâ€ÃƒÅ Ã‚Â¾Ã‚ÂµÃƒâ€žÃƒâ€”Ãƒâ€“Ã‚Â·ÃƒÂ»
 ÃƒÅ ÃƒÂ¤Ã‚Â³ÃƒÂ¶Ã‚Â²ÃƒÅ½ÃƒÅ ÃƒÂ½  : NONE
 Ã‚Â·Ã‚Âµ Ã‚Â»ÃƒËœ Ãƒâ€“Ã‚Âµ  : NONE
*****************************************************************************/
void LED_P6x8Char(uchar ucIdxX, uchar ucIdxY, uchar ucData)
{
    uchar i, ucDataTmp;

    ucDataTmp = ucData-32;
    if(ucIdxX > 122)
    {
        ucIdxX = 0;
        ucIdxY++;
    }

    LED_SetPos(ucIdxX, ucIdxY);

    for(i = 0; i < 6; i++)
    {
        LED_WrDat(F6x8[ucDataTmp][i]);
    }
}

/*****************************************************************************
 Ã‚ÂºÃ‚Â¯ ÃƒÅ ÃƒÂ½ ÃƒÆ’ÃƒÂ»  : LED_P6x8Str
 Ã‚Â¹Ã‚Â¦Ãƒâ€žÃƒÅ“ÃƒÆ’ÃƒÂ¨ÃƒÅ ÃƒÂ¶  : ÃƒÂÃ‚Â´ÃƒË†ÃƒÂ«Ãƒâ€™Ã‚Â»Ãƒâ€”ÃƒÂ©6x8Ã‚Â±ÃƒÂªÃƒâ€”Ã‚Â¼ASCIIÃƒâ€”Ãƒâ€“Ã‚Â·ÃƒÂ»Ã‚Â´Ã‚Â®
 ÃƒÅ ÃƒÂ¤ÃƒË†ÃƒÂ«Ã‚Â²ÃƒÅ½ÃƒÅ ÃƒÂ½  : UCHAR8 ucIdxX       ÃƒÂÃƒâ€ÃƒÅ Ã‚Â¾Ã‚ÂµÃƒâ€žÃ‚ÂºÃƒÂ¡Ãƒâ€”ÃƒÂ¸Ã‚Â±ÃƒÂª0~122
             UCHAR8 ucIdxY       Ãƒâ€™Ã‚Â³Ã‚Â·Ã‚Â¶ÃƒÅ½Ã‚Â§0Ã‚Â¡Ã‚Â«7
             UCHAR8 ucDataStr[]  ÃƒÂÃƒâ€ÃƒÅ Ã‚Â¾Ã‚ÂµÃƒâ€žÃƒâ€”Ãƒâ€“Ã‚Â·ÃƒÂ»Ã‚Â´Ã‚Â®
 ÃƒÅ ÃƒÂ¤Ã‚Â³ÃƒÂ¶Ã‚Â²ÃƒÅ½ÃƒÅ ÃƒÂ½  : NONE
 Ã‚Â·Ã‚Âµ Ã‚Â»ÃƒËœ Ãƒâ€“Ã‚Âµ  : NONE
*****************************************************************************/
void LED_P6x8Str(uchar ucIdxX, uchar ucIdxY, uchar ucDataStr[])
{
    uchar i, j, ucDataTmp;

    for (j = 0; ucDataStr[j] != '\0'; j++)
    {
        ucDataTmp = ucDataStr[j] - 32;
        if(ucIdxX > 122)
        {
            ucIdxX = 0;
            ucIdxY++;
        }

        LED_SetPos(ucIdxX,ucIdxY);

        for(i = 0; i < 6; i++)
        {
            LED_WrDat(F6x8[ucDataTmp][i]);
        }
        ucIdxX += 6;
    }

    return;
}/*********************************************** ******************************

                              ÃƒÂÃ‚Â´6x8Ã‚Â±ÃƒÂªÃƒâ€”Ã‚Â¼ÃƒË†ÃƒÂ½ÃƒÅ½Ã‚Â»ÃƒÅ ÃƒÂ½Ãƒâ€”Ãƒâ€“Ã‚Â´Ã‚Â®

*****************************************************************************/
void LED_P6x8Value(uchar ucIdxX, uchar ucIdxY,uint Data)
{
    uint DataTmp;
    //LED_SetPos(ucIdxX,ucIdxY);
    DataTmp = Data;
    LED_P6x8Char(ucIdxX,ucIdxY,DataTmp/100+48);
    LED_P6x8Char(ucIdxX+6,ucIdxY,DataTmp/10-DataTmp/100*10+48);
    LED_P6x8Char(ucIdxX+12,ucIdxY,DataTmp%10+48);

}
void LED_P6x8Value_signed(uchar ucIdxX, uchar ucIdxY,int Data)
{
    if (Data >= 0)
    {
        LED_P6x8Char(ucIdxX,ucIdxY,'+');
        LED_P6x8Value(ucIdxX+6,ucIdxY,Data);
    }
    else
    {
        LED_P6x8Char(ucIdxX,ucIdxY,'-');
        LED_P6x8Value(ucIdxX+6,ucIdxY,-Data);
    }
}
void LED_P6x8Value4(uchar ucIdxX,uchar ucIdxY , uint Data)
{
    uint DataTmp;
    DataTmp = Data;
    LED_P6x8Char(ucIdxX+18,ucIdxY,DataTmp % 10 + 48);
    LED_P6x8Char(ucIdxX+12,ucIdxY,( DataTmp /= 10 ) % 10 + 48);
    LED_P6x8Char(ucIdxX+6,ucIdxY,( DataTmp /= 10 ) % 10 + 48);
    LED_P6x8Char(ucIdxX,ucIdxY,( DataTmp /= 10 ) % 10 + 48);
}
void LED_P6x8Valuef(uchar ucIdxX,uchar ucIdxY , float Data)
{
    int DataTmp;
                                          DataTmp = Data * 100;
    LED_P6x8Char(ucIdxX+18,ucIdxY,DataTmp % 10 + 48);
    LED_P6x8Char(ucIdxX+12,ucIdxY,( DataTmp /= 10 ) % 10 + 48);
    LED_P6x8Char(ucIdxX+6,ucIdxY,( DataTmp /= 10 ) % 10 + 48);
    LED_P6x8Char(ucIdxX,ucIdxY,( DataTmp /= 10 ) % 10 + 48);
}
