/*
 * pushButton.c
 *
 * Created: 2019-12-07 10:44:36 AM
 *  Author: Abdo Sayed
 */ 

#include "pushButton.h"

#define BTN_Count_NUM		(4)

typedef struct ST_BTN
{
	En_buttonStatus_t state;
	uint8 reads[2];	
}ST_BTN; 
ST_BTN BTNs[BTN_MAX_NUM];
/**
 * Description: Initialize the BTN_x Pin state (where x 0, 1, 2, 3) to Input
 * @param btn_id: The btn to be initialized and it takes
 * 				  one of the enum (En_buttonId) parameters
 *
 */
void pushButton_Init(En_buttonId btn_id)
{
	for(int BTNCount = 0; BTNCount < 2; BTNCount++){
	switch (btn_id)
	{
		case BTN_0:
		/* Set direction for pin selected in port */
		gpioPinDirection(BTN_0_GPIO,BTN_0_BIT,INPUT);
		
		
		
		BTNs[BTNCount].state = Released;
		BTNs[BTNCount].reads[1] = 0;
		 
		
				
		break;
		
		case BTN_1:
		/* Set direction for pin selected in port */
		gpioPinDirection(BTN_1_GPIO,BTN_1_BIT,INPUT);
		
			
			BTNs[BTNCount].state = Released;
			BTNs[BTNCount].reads[1] = 0;
		
		break;
		
		case BTN_2:
		/* Set direction for pin selected in port */
		gpioPinDirection(BTN_2_GPIO,BTN_2_BIT,INPUT);
		
			
			BTNs[BTNCount].state = Released;
			BTNs[BTNCount].reads[1] = 0;
			
		
		break;
		
		case BTN_3:
		/* Set direction for pin selected in port */
		gpioPinDirection(BTN_3_GPIO,BTN_3_BIT,INPUT);
		
			BTNs[BTNCount].state = Released;
			BTNs[BTNCount].reads[1] = 0;
		
		break;
		
		default:
		/* Your code here */
		break;
	}
	}	//end of for 
}

/**
 * Description: read all BTN_x (where x 0, 1, 2, 3) states and store it in the program
 *
 * @note : this function must be called in the system tick handler or in the super loop handler
 */
void pushButton_Update(void)
{
	SwDelay_ms(30);
	for (int i = 0; i < BTN_Count_NUM; i++)		//for loop to get the first read after initial one
	{
		
		BTNs[i].reads[0] = BTNs[i].reads[1];	// to save old read and get new one to compare between them
		switch (i)
		{
			case BTN_0:
			BTNs[i].reads[1] = gpioPinRead(BTN_0_GPIO,BTN_0_BIT);
			break;
			
			case BTN_1:
			BTNs[i].reads[1] = gpioPinRead(BTN_1_GPIO,BTN_1_BIT);
			break;
			
			case BTN_2:
			BTNs[i].reads[1] = gpioPinRead(BTN_2_GPIO,BTN_2_BIT);
			break;
			
			case BTN_3:
			BTNs[i].reads[1] = gpioPinRead(BTN_3_GPIO,BTN_3_BIT);
			break;
			
			default:
			/* Your code here */
			break;
		}
		
		switch (BTNs[i].state)
		{
			case Released:
				if ( 0 == BTNs[i].reads[0] && 1 == BTNs[i].reads[1])
				{
					BTNs[i].state = Prepressed;
				}
								
			break;
			
			case Prepressed:
			
			if ( 1 == BTNs[i].reads[0] && 1 == BTNs[i].reads[1])
			{
				BTNs[i].state = Pressed;
			}
			
			break;
			
			case Pressed:
			
			if ( 1 == BTNs[i].reads[0] && 0 == BTNs[i].reads[1])
			{
				BTNs[i].state = Prereleased;
			}
			
			break;
			
			case Prereleased:
			
			if ( 0 == BTNs[i].reads[0] && 0 == BTNs[i].reads[1])
			{
				BTNs[i].state = Released;
			}
			
			break;
			
			default:
			/* Your code here */
			break;
		}
		
	}

}

/**
 * Description: read BTN_x (where x 0, 1, 2, 3) state which is stored in the program
 * 				in the update function
 *
 */
En_buttonStatus_t pushButton_GetStatus(En_buttonId btn_id)
{
	if (BTN_0 == btn_id)
	{
		return BTNs[BTN_0].state;
	}else if (BTN_1 == btn_id)
	{
		return BTNs[BTN_1].state;
	}else if (BTN_2 == btn_id)
	{
		return BTNs[BTN_2].state;
	}else if (BTN_3 == btn_id)
	{
		return BTNs[BTN_3].state;
	}else
	{
		return 0;
	}
}