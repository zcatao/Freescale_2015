
#include "Include.h"

double Angel_Correct = 0 ;

uint16_t AD_Power_5V = 0;



unsigned char DirectionControlOutCount;
float DirectionOutNew;
float DirectionOutOld;

void Key_Scan()
{
    //
    DDRJ_DDRJ6 = 0;
    DDRJ_DDRJ7 = 0;
    // 第一个按键 纠正温飘
    if (PTJ_PTJ6 == 0)
    {
        Delay_ms(10);
        if(PTJ_PTJ6 == 0){

            Angel_Correct = Car.Angel;

			//Car.Angel -= Angel_Correct; 

            Control_Info.MotorStop = 0;

            SPR = 0;
            while(PTJ_PTJ6 == 0);
            SPR = 1;

			MsTimeCount = 0;
			Control_Info.Speed_set = 0;
			Control_Info.Direction_P = 0;
        }
    }
    // 第二个按键 开关电机
    if (PTJ_PTJ7 == 0)
    {
      Delay_ms(1);
      if (PTJ_PTJ7 == 0)
      {
        Control_Info.MotorStop = (Control_Info.MotorStop + 1) % 2;

        SPR = 0;

        while(PTJ_PTJ7 == 0);

        SPR = 1;

		MsTimeCount = 0;
		Control_Info.Speed_set = 0;
		Control_Info.Direction_P = 0;
      }
    }
	// 第二个按键 开关电机
	if (PTJ_PTJ1 == 0)
	{
		Delay_ms(1);
		if (PTJ_PTJ1 == 0)
		{
			Control_Info.MotorStop = (Control_Info.MotorStop + 1) % 2;

			SPR = 0;

			while (PTJ_PTJ1 == 0);

			SPR = 1;

			MsTimeCount = 0;
			Control_Info.Speed_set = 0;
			Control_Info.Direction_P = 0;
		}
	}
}

void Key_Scan1()
{
	//
	DDRJ_DDRJ6 = 0;
	DDRJ_DDRJ7 = 0;
	// 第一个按键 纠正温飘
	if (PTJ_PTJ6 == 0)
	{
		Delay_ms(10);
		if (PTJ_PTJ6 == 0){

			Angel_Correct = Car.Angel;

			//Car.Angel -= Angel_Correct; 

			Control_Info.MotorStop = 0;

			duty++;

			SPR = 0;
			while (PTJ_PTJ6 == 0);
			SPR = 1;

			MsTimeCount = 0;
			Control_Info.Speed_set = 0;
			Control_Info.Direction_P = 0;
		}
	}
	// 第二个按键 开关电机
	if (PTJ_PTJ7 == 0)
	{
		Delay_ms(1);
		if (PTJ_PTJ7 == 0)
		{
			Control_Info.MotorStop = (Control_Info.MotorStop + 1) % 2;

			SPR = 0;

			duty = 0;

			while (PTJ_PTJ7 == 0);

			SPR = 1;

			MsTimeCount = 0;
			Control_Info.Speed_set = 0;
			Control_Info.Direction_P = 0;
		}
	}
	// 第二个按键 开关电机
	if (PTJ_PTJ1 == 0)
	{
		Delay_ms(1);
		if (PTJ_PTJ1 == 0)
		{
			Control_Info.MotorStop = (Control_Info.MotorStop + 1) % 2;

			SPR = 0;

			duty--;

			while (PTJ_PTJ1 == 0);

			SPR = 1;

			MsTimeCount = 0;
			Control_Info.Speed_set = 0;
			Control_Info.Direction_P = 0;
		}
	}
}

void AD_Capture()
{
    uchar i = 0;
    uint AD_Value;
    AD_Value = 0;
    for (i = 0; i < 10; ++i)
    {
        AD_Value += ATD0_Read(AD_Gyro_AR1);
    }
    Car.Gyro_AR1 =((int)(AD_Value / 10) - GYRO_AR1_ZERO ) * R_GYRO_AR1;
	
	AD_Value = 0;
	for (i = 0; i < 10; ++i)
	{
		AD_Value += ATD0_Read(AD_Gyro_AR2);
	}
	Car.Gyro_AR2 = ((int)(AD_Value / 10) - GYRO_AR2_ZERO) * R_GYRO_AR2;
	
	AD_Value = 0;
	for (i = 0; i < 10; ++i)
	{
		AD_Value += ATD0_Read(AD_Gyro_AR3);
	}
	Car.Gyro_AR3 = ((int)(AD_Value / 10) - GYRO_AR3_ZERO) * R_GYRO_AR3;

	Car.Gyro_Y = sqrt(Car.Gyro_AR2*Car.Gyro_AR2 + Car.Gyro_AR3*Car.Gyro_AR3);
	if (Car.Gyro_AR2 < 0){
		Car.Gyro_Y = -Car.Gyro_Y;
	}


    //AD_Value = 0;
    //for (i = 0; i < 10; ++i)
    //{
    //  AD_Value += ATD0_Read(AD_POWER_3V3);
    //}
    //AD_Power_5V = AD_Value / 10 ;
	AD_Value = 0;
	for (i = 0; i < 10; ++i)
	{
		AD_Value += ATD0_Read(AD_X);
	}
	Car.X = (int)(AD_Value / 10);
	Car.X = Car.X - X_ZERO;
	Car.X = Car.X - X_CORRECT;
	Car.X *= -X_RADIO;

	AD_Value = 0;
	for (i = 0; i < 10; ++i)
	{
		AD_Value += ATD0_Read(AD_Y);
	}
	Car.Y = ((int)(AD_Value / 10) - Y_ZERO);
	Car.Y *= Y_RADIO;

	AD_Value = 0;
	for (i = 0; i < 10; ++i)
	{
		AD_Value += ATD0_Read(AD_Z);
	}
	Car.Z = ((int)(AD_Value / 10) - Z_ZERO);
	Car.Z *= Z_RADIO;

//	OutData[0] = Car.Angel - Angel_Correct;

	/*Car.OE_Tube1_Value = ATD0_Read(14);
	Car.OE_Tube2_Value = ATD0_Read(15);
	*/
}

void SpeedDowmLineDetection()
{
	static Time = 0;

	if (MsTimeCount > Time + 1000){
		if (Car.OE_Tube1_Value > 500 &&
			Car.OE_Tube2_Value > 500){

			RightAngle_flag = (RightAngle_flag + 1) % 2;

			Time = MsTimeCount;

		}
	}
	if (RightAngle_flag == 1){
		//Control_Info.Speed_set = Speed_Set - 15;
	}
	else{
		//Control_Info.Speed_set = //Speed_Set;
	}

}

void AngelCalculate()
{
    float DeltaValue;
    static float AngelIntegral = 0;
    Car.Angel = AngelIntegral;
    DeltaValue = (Car.X - Car.Angel) / X_GYRO_AR1_ADJUST_TIME;
    AngelIntegral += (Car.Gyro_AR1 + DeltaValue) / 200; // PIT中断5ms一次 200HZ
}

void AngelCalulate_AR2(){

	Car.Angel_Y += Car.Gyro_Y / 200;

	if (Car.Angel_Y > 720){
		Car.Angel_Y = 0;
	}
	if (Car.Angel_Y < -720){
		Car.Angel_Y = 0;
	}

}

void AngelAdjust()
{
    float Motorvalue;
	//Angel_Correct = 0;
    Motorvalue = (Angel_Correct - Car.Angel ) * Control_Info.Angel_P +
                 (ANGEL_SPEED_SET - Car.Gyro_AR1) * Control_Info.Angel_D;
    Car.AngelControlOut = Motorvalue;
}

void Speed_Read()
{
  Car.Speed_R = PACNT;
  PACNT = 0;
  Car.Speed_L = PTM;

  PORTK_PK0 = 1;
  Delay_us(5);
  PORTK_PK0 = 0;              //ç¡¬ä»¶è®¡æ•°å™¨æ¸…é›¶

  if(PORTK_PK2 == 1)
    Car.Speed_L = -Car.Speed_L;
  if(PORTK_PK3 == 0)
    Car.Speed_R = -Car.Speed_R;

  //Car.Speed_L = Car.Speed_R;
}

void SpeedControl()
{
    static int SpeedControlIntegral = 0;
	static int SpeedOld;
    int SpeedDelta;
    float SpeedControlP;
    float SpeedControlD;
    float SpeedControlI;

	if (Control_Info.MotorStop == 1){
		SpeedControlIntegral = 0;
	}

    Car.Speed = (Car.Speed_L + Car.Speed_R) / 2;
    SpeedDelta = Control_Info.Speed_set - Car.Speed;

    SpeedControlP = SpeedDelta * Control_Info.Speed_P;
    SpeedControlI = SpeedDelta * Control_Info.Speed_I;


    SpeedControlIntegral += SpeedControlI;
    SpeedControlD = (Car.SpeedOld - Car.Speed) * Control_Info.Speed_D;
    Car.SpeedOld = Car.SpeedNew ;
	SpeedOld = Car.Speed;
    Car.SpeedNew = SpeedControlP + SpeedControlIntegral 
				 + SpeedControlD;


    if (SpeedControlIntegral > 60)
    {
    	SpeedControlIntegral = 60;
    }
    if (SpeedControlIntegral < -60)
    {
    	SpeedControlIntegral = -60 ;
    }


}

void SpeedControlOut()
{
    float delta;
    delta = Car.SpeedNew - Car.SpeedOld;
    Car.SpeedControlOut = delta * (SpeedControlOutCount + 1) / (20) + Car.SpeedOld;
    //if (Car.SpeedControlOut > 40)
    //{
    //	Car.SpeedControlOut = 40;
    //}
    //if (Car.SpeedControlOut < -40)
    //{
    //	Car.SpeedControlOut = -40;
    //}
}

void DirectionControl()
{
	float fp;
	float fd;
	char Error;
	//if (Error > 0){
	//	if (Error <= 10)
	//		Error *= Error;
	//	else
	//		Error = 100;
	//}
	//else{
	//	if (Error >= -10)
	//		Error *= Error;
	//	else
	//		Error = -100;
	//}

	if (RightAngle_flag == 1){

		if (Line_L_Miss == 1 &&
			Line_R_Miss == 0){

			SPR = 0;
			//fp = 200;

			fd = - Car.Gyro_Y * 1 ;

			DirectionOutOld = DirectionOutNew;

			DirectionOutNew = 170 + fd;

		}
		else if (Line_L_Miss == 0 &&
			Line_R_Miss == 1){
			//SPR = 0;
			//fp == -200;

			fd = - Car.Gyro_Y * 0.7;

			DirectionOutOld = DirectionOutNew;

			DirectionOutNew = -170 + fd;
		}
		else {
			//SPR = 1;
			Error = 62 - Middle_Line;

			fp = Error * Control_Info.Direction_P;// *Speed / 10;

			fd = Car.Gyro_Y * Control_Info.Direction_D;

			DirectionOutOld = DirectionOutNew;

			DirectionOutNew = fp + fd;
		}

	}

	else
	{
		//SPR = 1;
		Error = 62 - Middle_Line;

		fp = Error * Control_Info.Direction_P;// *Speed / 10;

		fd = Car.Gyro_Y * Control_Info.Direction_D;

		DirectionOutOld = DirectionOutNew;

		DirectionOutNew = fp + fd;

	}	
}

void DirectionControlout()
{
	float Delta;

	float DirectionOut;
	
	Delta = DirectionOutNew - DirectionOutOld;
	
	DirectionOut = Delta  * (DirectionControlOutCount + 1) / 2 + DirectionOutOld;

	Car.Direction_R = DirectionOut / 2;

	Car.Direction_L = - DirectionOutOld / 2;

}

void Motor_out2()
{
	// OutData[1] = Car.AngelControlOut;
	 //OutData[2] = Car.SpeedControlOut;
	 
	  Car.PWM_ValueR = Car.AngelControlOut //+ Car.Online_R ;
    									- Car.SpeedControlOut
    									+ Car.Direction_R;
    									;
    Car.PWM_ValueL = Car.AngelControlOut  //+ Car.Online_L ;
    									- Car.SpeedControlOut
    									+ Car.Direction_L;
    									;


  //  if (Angel_Correct - Car.Angel > 80 || Angel_Correct - Car.Angel  < -80)
  //  {
		//Control_Info.MotorStop = 1;
		//
  //  }
  //  if (Control_Info.MotorStop == 1)
  //  {

  //      Car.PWM_ValueL = 0;
  //      Car.PWM_ValueR = 0;
  //  }
  //  if (Car.PWM_ValueR > 0)
  //  {
  //      Car.PWM_ValueR += MOTOR_OUT_FORWARD_DEAL_R;

  //      if(Car.PWM_ValueR >= MOTOR_OUT_MAX-10)
  //          Car.PWM_ValueR = MOTOR_OUT_MAX-10;
  //      Motor_forward_0((uint8_t)Car.PWM_ValueR);
  //  }
  //  else
  //  {
  //      Car.PWM_ValueR -= MOTOR_OUT_BACK_DEAL_R;
  //      if(Car.PWM_ValueR <= MOTOR_OUT_MIN)
  //          Car.PWM_ValueR = MOTOR_OUT_MIN;
  //      Motor_back_0( (uint8_t)(-(Car.PWM_ValueR)));
  //  }

  //  if (Car.PWM_ValueL > 0)
  //  {
  //      Car.PWM_ValueL += MOTOR_OUT_FORWARD_DEAL_L;
  //      Car.PWM_ValueL *= MOTOR_OUT_FORWARD_RADIO_L;
  //      if( Car.PWM_ValueL >= MOTOR_OUT_MAX)
  //          Car.PWM_ValueL = MOTOR_OUT_MAX;
  //      Motor_forward_1 ( (uint8_t)Car.PWM_ValueL);
  //  }
  //  else
  //  {
  //      Car.PWM_ValueL -= MOTOR_OUT_BACK_DEAL_L;
  //      Car.PWM_ValueL *= MOTOR_OUT_BACK_RADIO_L;
  //      if( Car.PWM_ValueL <= MOTOR_OUT_MIN)
  //          Car.PWM_ValueL = MOTOR_OUT_MIN;
  //      Motor_back_1((uint8_t)(-(Car.PWM_ValueL)));
  //  }
}

void Motor_out()
{
	unsigned char temp_L;
	unsigned char temp_R;
//	OutData[2] = Car.AngelControlOut * 100;
	//OutData[2] = (Car.Angel - Angel_Correct) * 100;
	//OutData[3] = Car.SpeedControlOut * 100;		
	//if (Line_L_Miss == 1 && Line_R_Miss == 0){
	//	
	//	Car.Direction_R = 100;
	//	Car.Direction_L = -100;


	//} 
	//if (Line_R_Miss == 1 && Line_L_Miss == 0){

	//	Car.Direction_L = 100;
	//	Car.Direction_R = -100;
	//}
	Car.PWM_ValueR = Car.AngelControlOut //+ Car.Online_R ;
		- Car.SpeedControlOut
		+ Car.Direction_R; 
	
	Car.PWM_ValueL = Car.AngelControlOut  //+ Car.Online_L ;
		- Car.SpeedControlOut
		+ Car.Direction_L;
	if (Car.Angel - Angel_Correct > 60){
		Control_Info.MotorStop = 1;
	}
	if (Control_Info.MotorStop == 1)
	{
		Motor_brake();
		return;
	}
	else{
		if (Car.PWM_ValueL < 0)
		{
			if (Car.PWM_ValueL > -70){

				temp_L = 0.54*( - Car.PWM_ValueL) + 34; 
			}
			else{

				temp_L = - Car.PWM_ValueL + 5;
			}
			if (temp_L < 200)
				Motor_back_1(temp_L);
			else
				Motor_back_1(200);
		}
		else{
			temp_L = Car.PWM_ValueL + 4;

			Motor_forward_1(temp_L);
		}
		if (Car.PWM_ValueR < 0){
			
				temp_R = -Car.PWM_ValueR + 5;

				if (temp_L < 200)
					Motor_back_0(temp_R);
				else
					Motor_back_1(200);

		}
		else{

			temp_R = Car.PWM_ValueR + 4;

			Motor_forward_0(temp_R);
		}
	}
}


void Motor_out1()
{
	unsigned char temp_L;
	unsigned char temp_R;
	//	OutData[2] = Car.AngelControlOut * 100;
	//OutData[2] = (Car.Angel - Angel_Correct) * 100;
	//OutData[3] = Car.SpeedControlOut * 100;		
	//if (Line_L_Miss == 1 && Line_R_Miss == 0){
	//	
	//	Car.Direction_R = 100;
	//	Car.Direction_L = -100;


	//} 
	//if (Line_R_Miss == 1 && Line_L_Miss == 0){

	//	Car.Direction_L = 100;
	//	Car.Direction_R = -100;
	//}
	//Car.PWM_ValueR = Car.AngelControlOut //+ Car.Online_R ;
	//	- Car.SpeedControlOut
	//	+ Car.Direction_R;

	//Car.PWM_ValueL = Car.AngelControlOut  //+ Car.Online_L ;
	//	- Car.SpeedControlOut
	//	+ Car.Direction_L;

	Car.PWM_ValueL = duty;
	Car.PWM_ValueR = duty;
	if (Car.Angel - Angel_Correct > 60){
		Control_Info.MotorStop = 1;
	}
	if (Control_Info.MotorStop == 1)
	{
		Motor_brake();
		return;
	}
	else{
		if (Car.PWM_ValueL < 0)
		{
			if (Car.PWM_ValueL > -70){

				temp_L = 0.54*(-Car.PWM_ValueL) + 34;
			}
			else{

				temp_L = -Car.PWM_ValueL + 5;
			}
			if (temp_L < 200)
				Motor_back_1(temp_L);
			else
				Motor_back_1(200);
		}
		else{
			temp_L = Car.PWM_ValueL + 4;

			Motor_forward_1(temp_L);
		}
		if (Car.PWM_ValueR < 0){

			temp_R = -Car.PWM_ValueR + 5;

			if (temp_L < 200)
				Motor_back_0(temp_R);
			else
				Motor_back_1(200);

		}
		else{

			temp_R = Car.PWM_ValueR + 4;

			Motor_forward_0(temp_R);
		}
	}
}