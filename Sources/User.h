

#ifndef USER_H_
#define USER_H_


/****************************
*      MOROT OUT            *
*****************************
*/


#define MOTOR_OUT_MAX    200
#define MOTOR_OUT_MIN  -200
#define MOTOR_OUT_FORWARD_DEAL_L  0
#define MOTOR_OUT_BACK_DEAL_L     0	
#define MOTOR_OUT_FORWARD_DEAL_R  0
#define MOTOR_OUT_BACK_DEAL_R     0

#define MOTOR_OUT_FORWARD_RADIO_L 1
#define MOTOR_OUT_BACK_RADIO_L    1

/******************************
*         ATD0_COM
******************************/
#define  AD_POWER_3V3	0

#define  AD_Gyro_AR1    11
#define  AD_Gyro_AR2	12	
#define  AD_Gyro_AR3	13

#define  AD_X			8
#define  AD_Y			9
#define  AD_Z			10

#define  AD_OE_Tube1	14	
#define  AD_OE_Tube2	15

#define	 AD_CCD1		6
#define  AD_CCD2		7
/*****************************
*        AD_CONRRECT
******************************/


#define ANGEL_SET_VALUE  0
#define ANGEL_SPEED_SET  0

#define X_MAX            1980
#define X_MIN		     720
#define X_RADIO          (180.0 / (X_MAX - X_MIN))
#define X_ZERO           1365 - (5) / X_RADIO
#define X_CORRECT		 (415)

#define Y_MAX            2075
#define Y_MIN			 775
#define Y_RADIO          (180.0 / (Y_MAX - Y_MIN))
#define Y_ZERO           1458

#define Z_MAX            1700
#define Z_MIN		     455
#define Z_RADIO          (180.0 / (Z_MAX - Z_MIN))
#define Z_ZERO           1055

#define R_GYRO_AR1       0.35
#define GYRO_AR1_ZERO    (930 + (-6) / R_GYRO_AR1)

#define R_GYRO_AR2       0.35
#define GYRO_AR2_ZERO    (1208 + (0) * R_GYRO_AR2)

#define R_GYRO_AR3       0.4
#define GYRO_AR3_ZERO    (1559 + (0) * R_GYRO_AR3)

#define X_GYRO_AR1_ADJUST_TIME  2
//#define Y_GYRO_AR2_ADJUST_TIME  2
//#define Z_GYRO_AR3_ADJUST_TIME  2





//#define ANGEL_SET_VALUE  0
//#define ANGEL_SPEED_SET  0
//#define Z_MAX            1742
//#define Z_MIN            771
//#define Z_RADIO          (180.0 / (Z_MAX - Z_MIN))
//#define R_GYRO           0.65
//#define GYRO_ZERO        ((914.24) / R_GYRO)
//#define Z_ZERO           ((458.41-212+ 31.47)/ Z_RADIO)
//
//#define Z_GYRO_ADJUST_TIME  2


void Key_Scan(void);

void AD_Capture(void);

void AngelCalculate(void);

void AngelAdjust(void);

void Speed_Read(void);

void SpeedControl(void);

void SpeedControlOut(void);

void DirectionControl(void);

void DirectionControlout(void);

void Motor_out1(void);

void Motor_out(void);

void SpeedDowmLineDetection(void);


extern uint16_t AD_Power_5V;

extern unsigned char RightAngle_flag;
extern float DirectionOutNew;

#endif
