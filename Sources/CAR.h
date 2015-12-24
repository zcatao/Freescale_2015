
#ifndef CAR_H_
#define CAR_H_


struct car{
   int Speed_L;                                       // Ã¥Â·Â¦Ã§Â¼â€“Ã§Â ÂÃ¥â„¢Â¨Ã¥ÂÂÃ©Â¦Ë†Ã©â‚¬Å¸Ã¥ÂºÂ�?
   int Speed_R;                                       // Ã¥ÂÂ³Ã§Â¼â€“Ã§Â ÂÃ¥â„¢Â¨Ã¥ÂÂÃ©Â¦Ë†Ã©â‚¬Å¸Ã¥ÂºÂ�?
   int Speed;
   int AngelControlOut;
   int SpeedControlOut;
   int SpeedOld;
   int SpeedNew;
   int Direction_R;
   int Direction_L;
   double Angel;                                         // angel Ã¨Å¾ÂÃ¥ÂË†Ã¥â‚¬Â�?
   double Angel_Y;
   double Gyro_AR1;                                          // Ã¨Â§â€™Ã©â‚¬Å¸Ã¥ÂºÂ�?
   double Gyro_AR2;
   double Gyro_AR3;
   double Gyro_Y;
   double  X;
   double  Y;
   double  Z;                                             // ZÃ¥â€˜Â�?AD
   int PWM_ValueL;                                   // Ã¥Â·Â¦Ã§â€ÂµÃ¦Å“ÂºÃ¥ÂÂ Ã§Â©ÂºÃ¦Â¯â€
   int PWM_ValueR;                                   // Ã¥ÂÂ³Ã§â€ÂµÃ¦Å“ÂºÃ¥ÂÂ Ã§Â©ÂºÃ¦Â¯â€
   unsigned int OE_Tube1_Value;
   unsigned int OE_Tube2_Value;
};
//Ã¦Å½Â§Ã¥Ë†Â¶Ã¥Ââ€šÃ¦â€¢Â�?
struct control_info{
   unsigned char MotorStop;                                  //Ã¥ÂÅ“Ã¨Â½Â¦Ã¦Â â€¡Ã¥Â¿â€”Ã¤Â½Â�?
   char Speed_set;                                  //Ã©â‚¬Å¸Ã¥ÂºÂ¦Ã¨Â®Â¾Ã¥Â®Å�?
   char Angel_set;                                  //Ã¨Â§â€™Ã¥ÂºÂ¦Ã¨Â®Â¾Ã¥Â®Å¡
   float Z_set;
   float Angel_P;                                      //Ã¨Â§â€™Ã¥ÂºÂ¦P
   float Angel_D;                                      //Ã¨Â§â€™Ã¥ÂºÂ¦D
   float Speed_P;                                      //Ã©â‚¬Å¸Ã¥ÂºÂ¦P
   float Speed_I;                                      //Ã©â‚¬Å¸Ã¥ÂºÂ¦I
   float Speed_D;
   float Direction_P;
   float Direction_D;
};


extern struct car Car;
extern struct control_info Control_Info;
#endif
