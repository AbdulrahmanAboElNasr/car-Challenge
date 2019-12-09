/*
 * gpio.c
 *
 * Created: 2019-12-03 2:52:42 PM
 *  Author: Abdo Sayed
 */ 
#include "gpio.h"

//		SET GROUP OF BITS TOGETHER 
#define setBits(REG,BITM)	 REG |= (BITM)			//BITM -> bit mask all bits together
#define clearBits(REG,BITM)	 REG &= ~(BITM)
#define toggleBits(REG,BITM) REG ^= (BITM)
#define readBits(REG,BITM)  (REG&(BITM))



/*===========================PORT Control===============================*/


void gpioPortDirection(uint8 port, uint8 direction)
{
	switch (port)
	{
		case GPIOA:
			PORTA_DIR = direction;
			break;
		case GPIOB:
			PORTB_DIR = direction;
			break;
		case GPIOC:
			PORTC_DIR = direction;
			break;
		case GPIOD:
			PORTD_DIR = direction;
			break;
		default:
		/* Your code here */
			break;
	}
}

void gpioPortWrite(uint8 port, uint8 value)
{
	switch (port)
	{
		case GPIOA:
			PORTA_DATA = value;
			break;
		case GPIOB:
			PORTB_DATA = value;		
			break;
		case GPIOC:
			PORTC_DATA = value;
			break;
		case GPIOD:
			PORTD_DATA = value;
			break;
		default:
		/* Your code here */
			break;
	}
}

void gpioPortToggle(uint8 port)
{
	switch (port)
	{
		case GPIOA:
			PORTA_DATA = ~PORTA_DATA;
			break;
		case GPIOB:
			PORTB_DATA = ~PORTB_DATA;
			break;
		case GPIOC:
			PORTC_DATA = ~PORTC_DATA;
			break;
		case GPIOD:
			PORTD_DATA = ~PORTD_DATA;
			break;
		default:
		/* Your code here */
			break;
	}
}

uint8 gpioPortRead(uint8 port)
{
	switch (port)
	{
		case GPIOA:
			return PORTA_PIN;
			break;
		case GPIOB:
			return PORTB_PIN;
			break;
		case GPIOC:
			return PORTC_PIN;
			break;
		case GPIOD:
			return PORTD_PIN;
			break;
		default:
		/* Your code here */
			break;
	}
}

/*===========================PIN Control===============================*/

void gpioPinDirection(uint8 port, uint8 pins, uint8 direction)
{
	switch (port)
	{
		case GPIOA:
			if (direction)
			{
				SET_BIT(PORTA_DIR,pins);
			}else
			{
				CLR_BIT(PORTA_DIR,pins);
			}
			break;
		case GPIOB:
			if (direction)
			{
				SET_BIT(PORTB_DIR,pins);
			}else
			{
				CLR_BIT(PORTB_DIR,pins);
			}
			break;
		case GPIOC:
			if (direction)
			{
				SET_BIT(PORTC_DIR,pins);
			}else
			{
				CLR_BIT(PORTC_DIR,pins);
			}
			break;
		case GPIOD:
			if (direction)
			{
				SET_BIT(PORTD_DIR,pins);
			}else
			{
				CLR_BIT(PORTD_DIR,pins);
			}
			break;
		default:
		/* Your code here */
			break;
	}
}

void gpioPinWrite(uint8 port, uint8 pins, uint8 value)
{
	switch (port)
	{
		case GPIOA:
			if (value)
			{
				PORTA_DATA |= pins;
			}else
			{
				PORTA_DATA &= ~pins;
			}
			
		//	ASSIGN_BIT(PORTA_DATA,pins,value);		is not working when I use Ledon() from main
			break;
		case GPIOB:
				if (value)
				{
					PORTB_DATA |= pins;
				}else
				{
					PORTB_DATA &= ~pins;
				}
		//	ASSIGN_BIT(PORTB_DATA,pins,value);		is not working when I use Ledon() from main
			break;
		case GPIOC:
				if (value)
				{
					PORTC_DATA |= pins;
				}else
				{
					PORTC_DATA &= ~pins;
				}
		//	ASSIGN_BIT(PORTC_DATA,pins,value);		is not working when I use Ledon() from main
			break;
		case GPIOD:
				if (value)
				{
					PORTD_DATA |= pins;
				}else
				{
					PORTD_DATA &= ~pins;
				}
		//	ASSIGN_BIT(PORTD_DATA,pins,value);		is not working when I use Ledon() from main
			break;
		default:
		/* Your code here */
			break;
	}
}

void gpioPinToggle(uint8 port, uint8 pins)
{
	switch (port)
	{
		case GPIOA:
			TOGGLE_BIT(PORTA_DATA,pins);
			break;
		case GPIOB:
			TOGGLE_BIT(PORTB_DATA,pins);
			break;
		case GPIOC:
			TOGGLE_BIT(PORTC_DATA,pins);
			break;
		case GPIOD:
			TOGGLE_BIT(PORTD_DATA,pins);
			break;
		default:
		/* Your code here */
			break;
	}
}

uint8 gpioPinRead(uint8 port, uint8 pin)
{
	switch (port)
	{
		case GPIOA:
			return GET_BIT(PORTA_PIN,pin);
			break;
		case GPIOB:
			return GET_BIT(PORTB_PIN,pin);
			break;
		case GPIOC:
			return GET_BIT(PORTC_PIN,pin);
			break;
		case GPIOD:
			return GET_BIT(PORTD_PIN,pin);
			break;
		default:
		/* Your code here */
			break;
	}
}

/*===========================Upper Nibble Control===============================*/

void gpioUpperNibbleDirection(uint8 port, uint8 direction)
{
	switch (port)
	{
		case GPIOA:
			if (direction)
			{
				setBits(PORTA_DIR,0xF0);
			} 
			else
			{
				clearBits(PORTA_DIR,0xF0);
			}
			break;
		case GPIOB:
			if (direction)
			{
				setBits(PORTB_DIR,0xF0);
			}
			else
			{
				clearBits(PORTB_DIR,0xF0);
			}
			break;
		case GPIOC:
			if (direction)
			{
				setBits(PORTC_DIR,0xF0);
			}
			else
			{
				clearBits(PORTC_DIR,0xF0);
			}
			break;
		case GPIOD:
			if (direction)
			{
				setBits(PORTD_DIR,0xF0);
			}
			else
			{
				clearBits(PORTD_DIR,0xF0);
			}
			break;
		default:
		/* Your code here */
			break;
	}
}

void gpioUpperNibbleWrite(uint8 port, uint8 value)
{
	switch(port)
	{
	case GPIOA:
		setBits(PORTA_DATA,value&0XF0);
	break;
	case GPIOB:
		setBits(PORTB_DATA,value&0XF0);
		break;
	case GPIOC:
		setBits(PORTC_DATA,value&0XF0);
		break;
	case GPIOD:
		setBits(PORTD_DATA,value&0XF0);
		break;
	default:
	/* Your code here */
	break;
}
}

void gpioUpperNibbleToggle(uint8 port)
{
	switch(port)
	{
		case GPIOA:
		toggleBits(PORTA_DATA,0XF0);
		break;
		case GPIOB:
		toggleBits(PORTB_DATA,0XF0);
		break;
		case GPIOC:
		toggleBits(PORTC_DATA,0XF0);
		break;
		case GPIOD:
		toggleBits(PORTD_DATA,0XF0);
		break;
		default:
		/* Your code here */
		break;
	}
}

uint8 gpioUpperNibbleRead(uint8 port)
{
	switch(port)
	{
		case GPIOA:
		return readBits(PORTA_PIN,0xF0);
		break;
		case GPIOB:
		return(PORTB_PIN,0xF0);
		break;
		case GPIOC:
		return(PORTC_PIN,0xF0);
		break;
		case GPIOD:
		return(PORTD_PIN,0xF0);
		break;
		default:
		/* Your code here */
		break;
	}
}

/*===========================Lower Nibble Control===============================*/

void gpioLowerNibbleDirection(uint8 port, uint8 direction)
{
	switch (port)
	{
		case GPIOA:
		if (direction)
		{
			setBits(PORTA_DIR,0x0F);
		}
		else
		{
			clearBits(PORTA_DIR,0x0F);
		}
		break;
		case GPIOB:
		if (direction)
		{
			setBits(PORTB_DIR,0x0F);
		}
		else
		{
			clearBits(PORTB_DIR,0x0F);
		}
		break;
		case GPIOC:
		if (direction)
		{
			setBits(PORTC_DIR,0x0F);
		}
		else
		{
			clearBits(PORTC_DIR,0x0F);
		}
		break;
		case GPIOD:
		if (direction)
		{
			setBits(PORTD_DIR,0x0F);
		}
		else
		{
			clearBits(PORTD_DIR,0x0F);
		}
		break;
		default:
		/* Your code here */
		break;
	}
}

void gpioLowerNibbleWrite(uint8 port, uint8 value)
{
	switch(port)
	{
		case GPIOA:
		setBits(PORTA_DATA,value&0X0F);
		break;
		case GPIOB:
		setBits(PORTB_DATA,value&0X0F);
		break;
		case GPIOC:
		setBits(PORTC_DATA,value&0X0F);
		break;
		case GPIOD:
		setBits(PORTD_DATA,value&0X0F);
		break;
		default:
		/* Your code here */
		break;
	}
}

void gpioLowerNibbleToggle(uint8 port)
{
	switch(port)
	{
		case GPIOA:
		toggleBits(PORTA_DATA,0X0F);
		break;
		case GPIOB:
		toggleBits(PORTB_DATA,0X0F);
		break;
		case GPIOC:
		toggleBits(PORTC_DATA,0X0F);
		break;
		case GPIOD:
		toggleBits(PORTD_DATA,0X0F);
		break;
		default:
		/* Your code here */
		break;
	}
}

uint8 gpioLowerNibbleRead(uint8 port)
{
	switch(port)
	{
		case GPIOA:
		return readBits(PORTA_PIN,0x0F);
		break;
		case GPIOB:
		return(PORTB_PIN,0x0F);
		break;
		case GPIOC:
		return(PORTC_PIN,0x0F);
		break;
		case GPIOD:
		return(PORTD_PIN,0x0F);
		break;
		default:
		/* Your code here */
		break;
	}
}
