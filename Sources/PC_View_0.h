




#ifndef PC_VIEW_H_
#define PC_VIEW_H_



#define ANGEL_P         SEND3
#define ANGEL_D         SEND4
#define SPEED_P         SEND5
#define SPEED_I         SEND6
#define SPEED_SET       SEND7       
#define ANGEL_SET       SEND8



void PRM_Updata_0(void);

void SendHex_0(unsigned char hed);

void SendImageData_0(unsigned char *ImageData);

void SCI_LOOK_0(unsigned char*);

void OutPut_Data_0(void);





extern float OutData[4];

extern unsigned char g_RTBuf[4];

extern unsigned char g_STBuf[4];



#endif
