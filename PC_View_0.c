



#include "Include.h"

//float OutData[4];
//unsigned char g_RTBuf[4];
//unsigned char g_STBuf[4];


float PC_Cmd_Value = 0;

/************************
*      virtual scope
************************/
unsigned short CRC_CHECK_0(unsigned char *Buf, unsigned char CRC_CNT)
{
	unsigned short CRC_Temp;
	unsigned char i, j;
	CRC_Temp = 0xffff;

	for (i = 0; i<CRC_CNT; i++){
		CRC_Temp ^= Buf[i];
		for (j = 0; j<8; j++) {
			if (CRC_Temp & 0x01)
				CRC_Temp = (CRC_Temp >> 1) ^ 0xa001;
			else
				CRC_Temp = CRC_Temp >> 1;
		}
	}
	return(CRC_Temp);
}

void OutPut_Data_0(void)
{
	int temp[4] = { 0 };
	unsigned int temp1[4] = { 0 };
	unsigned char databuf[10] = { 0 };
	unsigned char i;
	unsigned short CRC16 = 0;
	for (i = 0; i<4; i++)
	{

		temp[i] = (int)OutData[i];
		temp1[i] = (unsigned int)temp[i];

	}

	for (i = 0; i<4; i++)
	{
		databuf[i * 2] = (unsigned char)(temp1[i] % 256);
		databuf[i * 2 + 1] = (unsigned char)(temp1[i] / 256);
	}

	CRC16 = CRC_CHECK_0(databuf, 8);
	databuf[8] = CRC16 % 256;
	databuf[9] = CRC16 / 256;

	for (i = 0; i<10; i++)
		SCI0_Send(databuf[i]);
	//uart_putchar(databuf[i]);
}

void PRM_Updata_0()
{
	if (g_SCI0_READ_flag == 1)                                                //ÃƒË†ÃƒÂ§Ã‚Â¹ÃƒÂ»Ãƒâ€°ÃƒÂÃƒÅ½Ã‚Â»Ã‚Â»ÃƒÂºÃƒÆ’ÃƒÂ¼ÃƒÂÃƒÂ®Ã‚Â¸ÃƒÂ¼ÃƒÂÃƒâ€š
	{
		g_SCI0_READ_flag = 0;
		if (g_STBuf[1] & 0X40)
		{
			PC_Cmd_Value = (g_STBuf[2] - 1) + g_STBuf[3] / 100.0;
		}
		else{
			PC_Cmd_Value = (g_STBuf[2] - 1) * 100 + g_STBuf[3] - 1;
		}
		if (g_STBuf[1] & 0X80)
		{
			PC_Cmd_Value = 0 - PC_Cmd_Value;
		}
		LED_P6x8Str(0, 0, "PC:");
		LED_P6x8Value(18, 0, (uint)PC_Cmd_Value / 1000);
		LED_P6x8Value(36, 0, (uint)PC_Cmd_Value % 1000);
		switch (g_STBuf[1] & 0x3F)
		{
		default:
		case SEND1:; break;
		case SEND2:
		case ANGEL_P:{
			Control_Info.Angel_P = PC_Cmd_Value;
			break;
		}
		case ANGEL_D:{
			Control_Info.Angel_D = PC_Cmd_Value;
			break;
		}
		case SPEED_P:{
			Control_Info.Speed_P = PC_Cmd_Value;
			break;

		}
		case SPEED_I:{
			Control_Info.Speed_I = PC_Cmd_Value;
			break;
		}
		case ANGEL_SET:{
			Control_Info.Direction_P = PC_Cmd_Value;
			break;
		}
		case SPEED_SET:{
			Control_Info.Z_set = PC_Cmd_Value;
			break;
		}
		case SEND9:
		case SPEED_CT_E:
		case SPEED_CT: {
			Control_Info.Speed_set = -(PC_Cmd_Value);
			while (PC_Cmd_Value--)
			{
				SPR_init();
			}
			break;
		}
		case START_CAR: {
			Control_Info.MotorStop = 0;
			break;                                //ÃƒÂÃ‚Â£Ã‚Â³Ã‚ÂµÃƒâ€”Ã‚Â´ÃƒÅ’Ã‚Â¬ÃƒÅ½Ã‚Â»Ãƒâ€¡ÃƒÂ¥ÃƒÂÃƒÂ£
		}
		case STOP_CAR: {
			Control_Info.MotorStop = 1;
			break;                                 //ÃƒÂÃ‚Â£Ã‚Â³Ã‚ÂµÃƒâ€”Ã‚Â´ÃƒÅ’Ã‚Â¬Ãƒâ€“ÃƒÆ’ÃƒÅ½Ã‚Â»
		}
		}
	}
}

/****************************
*        红树伟业PC_ccd
*****************************/
void SCI_LOOK_0(unsigned char *Pixel)
{
	int i;
	for (i = 0; i<128; i++){
		if (Pixel[i] == 0xFF){
			Pixel[i] = 0xFE; //???FF?FE???????
		}
		SCI0_Send(Pixel[i]);
	}
	SCI0_Send(0xFF);
}
/*********************
*     up_machine
**********************
*/
void Send_PC_0(uchar index, double value)
{

	if (value < 0)
		index |= 0x80;
	if ((uint)(value * 100) % 100 != 0)
	{
		index |= 0x40;
		value *= 100;
	}

	g_RTBuf[0] = SEND_HEAD;
	g_RTBuf[1] = index;
	g_RTBuf[2] = (uint)value / 100 + 1;
	g_RTBuf[3] = (uint)value % 100;

	SCI0_Send(g_RTBuf[0]);
	SCI0_Send(g_RTBuf[1]);
	SCI0_Send(g_RTBuf[2]);
	SCI0_Send(g_RTBuf[3]);

}

/*******************************
*        LANDZO_CCD
*****************************/
void SendHex_0(unsigned char hex) {
	unsigned char temp;
	temp = hex >> 4;
	if (temp < 10) {
		SCI0_Send(temp + '0');
	}
	else {
		SCI0_Send(temp - 10 + 'A');
	}
	temp = hex & 0x0F;
	if (temp < 10) {
		SCI0_Send(temp + '0');
	}
	else {
		SCI0_Send(temp - 10 + 'A');
	}
}

void SendImageData_0(unsigned char * ImageData) {

	unsigned char i;
	unsigned char crc = 0;
	unsigned char temp;

	/* Send Data */
	SCI0_Send('*');
	SCI0_Send('L');
	SCI0_Send('D');

	SendHex_0(0);
	SendHex_0(0);
	SendHex_0(0);
	SendHex_0(0);

	for (i = 0; i<128; i++) {
		//temp = *ImageData++;
		//if (i == Middle_Line)
		//	SendHex(0x00);
		//else if (i == Line_L){
		//	SendHex(0x00);
		//}
		//else if (i == Line_R){
		//	SendHex(0x00);
		//}  
		//else
		//{
		//	SendHex(temp);
		//}

		SendHex_0(*ImageData++);
	}

	SendHex_0(crc);
	SCI0_Send('#');
}