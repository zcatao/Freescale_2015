 



#include "Include.h"

float OutData[4];
unsigned char g_RTBuf[4];
unsigned char g_STBuf[4];


float PC_Cmd_Value = 0;

/************************
*      virtual scope
************************/
unsigned short CRC_CHECK(unsigned char *Buf, unsigned char CRC_CNT)
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

void OutPut_Data(void)
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

	CRC16 = CRC_CHECK(databuf, 8);
	databuf[8] = CRC16 % 256;
	databuf[9] = CRC16 / 256;

	for (i = 0; i<10; i++)
		SCI1_Send(databuf[i]);
	//uart_putchar(databuf[i]);
}

void PRM_Updata()
{
	if (g_SCI1_READ_flag == 1)                                                //ÃƒË†ÃƒÂ§Ã‚Â¹ÃƒÂ»Ãƒâ€°ÃƒÂÃƒÅ½Ã‚Â»Ã‚Â»ÃƒÂºÃƒÆ’ÃƒÂ¼ÃƒÂÃƒÂ®Ã‚Â¸ÃƒÂ¼ÃƒÂÃƒâ€š
	{
		g_SCI1_READ_flag = 0;
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
			Control_Info.Direction_D = PC_Cmd_Value;
			break;
		}
		case SEND9:
		case SPEED_CT_E:
		case SPEED_CT: {
			Control_Info.Speed_set = -(PC_Cmd_Value);
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
void SCI_LOOK(unsigned char *Pixel)
{
	int i;
	for (i = 0; i<128; i++){
		if (Pixel[i] == 0xFF){
			Pixel[i] = 0xFE; //???FF?FE???????
		}
		SCI1_Send(Pixel[i]);
	}
	SCI1_Send(0xFF);
}
/*********************
*     up_machine
**********************
*/
void Send_PC(uchar index, double value)
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

	SCI1_Send(g_RTBuf[0]);
	SCI1_Send(g_RTBuf[1]);
	SCI1_Send(g_RTBuf[2]);
	SCI1_Send(g_RTBuf[3]);

}


void PRM_LED_PUTOUT()
{
	uint8_t i = 0;
	//Send_PC(NUM14,Car.PWM_ValueR);
	//LED_P6x8Str(0, 1, "Cmd: ");
	//LED_P6x8Valuef(30, 1, PC_Cmd_Value);

	LED_P6x8Str(64, 1, "Line：");
	LED_P6x8Value(94, 1, Middle_Line);


	//Send_PC(NUM5,Control_Info.Angel_P);
	//LED_P6x8Str(0, 2, "Ang_P");
	//LED_P6x8Valuef(30, 2, Control_Info.Angel_P);

	LED_P6x8Str(64, 2, "Dir_p");
	LED_P6x8Valuef(94, 2, Control_Info.Direction_P);

	//Send_PC(NUM6,Control_Info.Angel_D);
	//LED_P6x8Str(0, 3, "Ang_D");
	//LED_P6x8Valuef(30, 3, Control_Info.Angel_D);

	LED_P6x8Str(64, 3, "Dir_D");
	LED_P6x8Valuef(94, 3, Control_Info.Direction_D);

	//Send_PC(NUM7,Control_Info.Speed_P);
	///LED_P6x8Str(0, 4, "Spe_P");
	//LED_P6x8Valuef(30, 4, Control_Info.Speed_P);

	LED_P6x8Str(64, 4, "Timer:");
	LED_P6x8Value4(94, 4, MsTimeCount);

	//Send_PC(NUM8,Control_Info.Speed_I);
	//LED_P6x8Str(0, 5, "Spe_I");
	//LED_P6x8Valuef(30, 5, Control_Info.Speed_I);

	//LED_P6x8Str(64, 5, "Point");
	//LED_P6x8Value(95, 5, integration_point);



	//LED_P6x8Str(0,6,"Z :");
	// LED_P6x8Value(30,6,Car.Z);
	LED_P6x8Str(64, 6, "S_Fg:");
	if (Single_Line_Boot_Flag == 1){
		LED_SetPos(110, 6);
		LED_WrDat(0xff);
		LED_SetPos(111, 6);
		LED_WrDat(0xff);
		LED_SetPos(112, 6);
		LED_WrDat(0XFF);
	}
	else
	{
		LED_SetPos(110, 6);
		LED_WrDat(0x00);
		LED_SetPos(111, 6);
		LED_WrDat(0X00);
		LED_SetPos(112, 6);
		LED_WrDat(0X00);
	}
	for (i = 0; i < 128; i++){
		LED_SetPos(i, 7);
		LED_WrDat(0x00);
	}

	LED_SetPos(Line_L - 1, 7);
	LED_WrDat(0xff);

	LED_SetPos(Line_L, 7);
	LED_WrDat(0xff);

	LED_SetPos(Line_L + 1, 7);
	LED_WrDat(0xff);

	LED_SetPos(Line_R - 1, 7);
	LED_WrDat(0xff);

	LED_SetPos(Line_R, 7);
	LED_WrDat(0xff);

	LED_SetPos(Line_R + 1, 7);
	LED_WrDat(0xff);

}
/*******************************
*        LANDZO_CCD
*****************************/
void SendHex(unsigned char hex) {
	unsigned char temp;
	temp = hex >> 4;
	if (temp < 10) {
		SCI1_Send(temp + '0');
	}
	else {
		SCI1_Send(temp - 10 + 'A');
	}
	temp = hex & 0x0F;
	if (temp < 10) {
		SCI1_Send(temp + '0');
	}
	else {
		SCI1_Send(temp - 10 + 'A');
	}
}

void SendImageData(unsigned char * ImageData) {

	unsigned char i;
	unsigned char crc = 0;
	unsigned char temp;

	/* Send Data */
	SCI1_Send('*');
	SCI1_Send('L');
	SCI1_Send('D');

	SendHex(0);
	SendHex(0);
	SendHex(0);
	SendHex(0);

	for (i = 0; i<128; i++) {
		//temp = *ImageData++;
		//if (i == Middle_Line){
		//	//ImageData++;
		//	SendHex(0x00);
		//}
		//	
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
			SendHex(*ImageData++);
	}

	SendHex(crc);
	SCI1_Send('#');
}