/*
 * MotorDC.c
 *
 * Created: 2019-12-09 2:35:30 PM
 *  Author: Abdo Sayed
 */

#include "MotorDC.h" 
/**
 * Description: 
 * @param
 */
void MotorDC_Init(En_motorType_t MOT_x)
{
	switch (MOT_x)
	{
		case MOT_1:
		/* Your code here */
		SET_BIT(PORTD_DIR,MOTOR_EN_1_BIT);
		SET_BIT(PORTD_DIR,MOTOR_OUT_1A_BIT);
		SET_BIT(PORTD_DIR,MOTOR_OUT_1B_BIT);
		break;
		
		case MOT_2:
		/* Your code here */
		SET_BIT(PORTD_DIR,MOTOR_EN_2_BIT);
		SET_BIT(PORTD_DIR,MOTOR_OUT_2A_BIT);
		SET_BIT(PORTD_DIR,MOTOR_OUT_2B_BIT);
		break;
		
		default:
		/* Your code here */
		break;
	}
}

/**
 * Description: 
 * @param 
 * @param 
 */
void MotorDC_Dir(En_motorType_t MOT_x, En_motorDir_t dir)
{
	switch (dir)
	{
		case STOP:
		/* Your code here */
		switch (MOT_x)
		{
			case MOT_1:
			/* Your code here */
			CLR_BIT(PORTD_DATA,MOTOR_OUT_1A_BIT);
			CLR_BIT(PORTD_DATA,MOTOR_OUT_1B_BIT);
			break;
			
			case MOT_2:
			/* Your code here */
			CLR_BIT(PORTD_DATA,MOTOR_OUT_2A_BIT);
			CLR_BIT(PORTD_DATA,MOTOR_OUT_2B_BIT);
			break;
			
			default:
			/* Your code here */
			break;
		}
		
		break;
		
		case FORWARD:
		/* Your code here */
		switch (MOT_x)
		{
			case MOT_1:
			/* Your code here */
			SET_BIT(PORTD_DATA,MOTOR_OUT_1A_BIT);
			CLR_BIT(PORTD_DATA,MOTOR_OUT_1B_BIT);
			break;
			
			case MOT_2:
			/* Your code here */
			SET_BIT(PORTD_DATA,MOTOR_OUT_2A_BIT);
			CLR_BIT(PORTD_DATA,MOTOR_OUT_2B_BIT);
			break;
			
			default:
			/* Your code here */
			break;
		}
		
		break;
		
		case BACKWARD:
		/* Your code here */
		switch (MOT_x)
		{
			case MOT_1:
			/* Your code here */
			CLR_BIT(PORTD_DATA,MOTOR_OUT_1A_BIT);
			SET_BIT(PORTD_DATA,MOTOR_OUT_1B_BIT);
			break;
			
			case MOT_2:
			/* Your code here */
			CLR_BIT(PORTD_DATA,MOTOR_OUT_2A_BIT);
			SET_BIT(PORTD_DATA,MOTOR_OUT_2B_BIT);
			break;
			
			default:
			/* Your code here */
			break;
		}
		
		break;
		
		default:
		/* Your code here */
		break;
	}
}

/**
 * Description: 
 * @param 
 */
void MotorDC_Speed_PollingWithT0(uint16 speed)
{
	timer1SwPWM(speed , 20);
}

/**
 * Description: set the port value (which is PORT register)
 * @param 
 */
void MotorDC_Speed_HwPWM(uint8 speed);

