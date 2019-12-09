/*
 * SprintDay4.c
 *
 * Created: 2019-12-03 1:35:26 PM
 *  Author: Abdo Sayed
 */ 
#include "led.h"
#include "softwareDelay.h"
#include "gpio.h"
#include "pushButton.h"
#include "timers.h"
#include "avr/delay.h"
//#include "avr/interrupt.h"		use interrupt.h instead of it
#include "interrupt.h"
#include "MotorDC.h"



#define Go			0
#define Stop		1
#define	GetReady	2


int main(void)
{
	static uint8 statex = Go;
	static uint8 flag = 0;
	uint8 count = 0;
	pushButton_Init(BTN_0);
	En_buttonStatus_t btn_state;
	
	Led_Init(LED_0);
	Led_Init(LED_1);
	Led_Init(LED_2);
	timer0Init(T0_NORMAL_MODE,T0_OC0_DIS,T0_PRESCALER_64,0,0,T0_POLLING);
	timer1Init(T1_NORMAL_MODE,T1_OC1_DIS,T1_PRESCALER_64,0,0,0,0,T1_POLLING);
	
	MotorDC_Init(MOT_1);
	MotorDC_Dir(MOT_1,FORWARD);
	//MotorDC_Init(MOT_2);
	//MotorDC_Dir(MOT_2,FORWARD);

	int countMotor = 30;
	
	
	for (int j = 1; j<5 ; j++)
	{
		countMotor += 35;
		for (int i=1 ; i<500 ; i++)
		{
			MotorDC_Speed_PollingWithT0(countMotor);
			//timer0Delay_ms(20);
		}
		
	}
	
	
	
	for (int j = 1; j<5 ; j++)
	{
		countMotor -= 35;
		for (int i=1 ; i<500 ; i++)
		{
			MotorDC_Speed_PollingWithT0(countMotor);
			//timer0Delay_ms(20);
		}
		
	}
	
	timer0Delay_ms(1000);
	//MotorDC_Dir(MOT_1,BACKWARD);
	
	for (int j = 1; j<5 ; j++)
	{
		countMotor += 15;
		for (int i=1 ; i<500 ; i++)
		{
			MotorDC_Speed_PollingWithT0(countMotor);
			//timer0Delay_ms(20);
		}
		
	}
	
    while(1)
    {
		//TODO:: Please write your application code 
		
				
		
    }

}





/* 

btn_state = pushButton_GetStatus(BTN_0);
switch (statex)
{
	case Go:
	Led_On(LED_0);
	Led_Off(LED_1);
	Led_Off(LED_2);
	//SwDelay_ms(1000);
	//_delay_ms(1000);
	//timer0Delay_ms(2000);
	timer1Delay_ms(2000);
	statex = Stop;
	break;
	
	case Stop:
	if (Prepressed == btn_state)
	{
		statex = Go;
	}
	Led_Off(LED_0);
	Led_On(LED_1);
	Led_Off(LED_2);
	//SwDelay_ms(1000);
	//_delay_ms(1000);
	//timer0Delay_ms(1000);
	timer1Delay_ms(2000);
	statex = GetReady;
	break;
	
	case GetReady:
	if (Prepressed == btn_state)
	{
		statex = Go;
	}
	Led_Off(LED_0);
	Led_Off(LED_1);
	Led_On(LED_2);
	//SwDelay_ms(1000);
	//_delay_ms(1000);
	//timer0Delay_ms(1000);
	timer1Delay_ms(2000);
	statex = Go;
	break;
	
	default:
	// Your code here
	break;
}


*/

/**

/////////////////////////////
Led_On(LED_0);
Led_Off(LED_1);
Led_Off(LED_2);
_delay_ms(1000);

Led_Off(LED_0);
Led_On(LED_1);
Led_Off(LED_2);
_delay_ms(1000);

Led_Off(LED_0);
Led_Off(LED_1);
Led_On(LED_2);
_delay_ms(1000);

*/


/*


for (int i=1; i<=255; i++)
{
	timer1SwPWM(i,20);
	
	
}
for (int i = 255;i>1;i--)
{
	timer1SwPWM(i,20);
}


*/