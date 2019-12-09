/*
 * timers.c
 *
 * Created: 2019-12-08 12:12:28 PM
 *  Author: Abdo Sayed
 */ 

#include "timers.h"

// for timer0 
En_timer0perscaler_t gu8_Timer0prescale;

// for timer1
En_timer1perscaler_t gu8_Timer1prescale;

// for timer2
En_timer2perscaler_t gu8_Timer2prescale;

/*===========================Timer0 Control===============================*/
/**
 * Description:
 * @param control
 * @param initialValue
 * @param outputCompare
 * @param interruptMask
 */
void timer0Init(En_timer0Mode_t mode,En_timer0OC_t OC0,En_timer0perscaler_t prescal, uint8 initialValue, uint8 outputCompare, uint8 interruptMask)
{
	TCCR0 = mode | OC0;						//Register for control 
	TCNT0 = initialValue;
	OCR0  = outputCompare;
	TIMSK |= interruptMask;					//Register or to save the values
	
	gu8_Timer0prescale = prescal;					// save prescaler to use it in start and stop function	
}

/**
 * Description:
 * @param value
 */
void timer0Set(uint8 value)
{
	TCNT0 = value;
}

/**
 * Description:
 * @return
 */
uint8 timer0Read(void)
{
	return TCNT0;
}

/**
 * Description:
 */
void timer0Start(void)
{
	TCCR0 |= gu8_Timer0prescale;		// enable clock to start the timer 
}

/**
 * Description:
 */
void timer0Stop(void)
{
	TCCR0 &= 0xF8;			// disable the clock bits 0,1,2 by clearing them
}

/**
 * Description:
 * @param delay
 */
void timer0Delay_ms(uint32 delay)
{
	gu8_Timer0prescale = T0_PRESCALER_64;
	timer0Stop();
	timer0Set(130);				// 255-125 for 1 milli second
	timer0Start();
	
	while(delay)
	{
		while(!GET_BIT(TIFR,BIT0));
		SET_BIT(TIFR,BIT0);		// bit 0 is cleared by write a logic 1 to this bit
		timer0Set(130);			// 255-125 for 1 milli second
		delay--;
	}
	
	timer0Stop();
}

/**
 * Description:
 * @param dutyCycle
 */
void timer0SwPWM(uint8 dutyCycle,uint8 freq);



/*===========================Timer1 Control===============================*/
/**
 * Description:
 * @param controlA
 * @param controlB
 * @param initialValue
 * @param outputCompare
 * @param interruptMask
 */
void timer1Init(En_timer1Mode_t mode,En_timer1OC_t OC,En_timer1perscaler_t prescal, uint16 initialValue, uint16 outputCompareA, uint16 outputCompareB,
				uint16 inputCapture, uint8 interruptMask)
{
	TCCR1 = mode | OC;
	TCNT1 = initialValue;
	OCR1A = outputCompareA;
	OCR1B = outputCompareB;
	ICR1 = inputCapture;
	TIMSK |= interruptMask;	
	
	gu8_Timer1prescale = prescal;
}

/**
 * Description:
 * @param value
 */
void timer1Set(uint16 value)
{
	TCNT1 = value;
}

/**
 * Description:
 * @return
 */
uint16 timer1Read(void)
{
	return TCNT1;
}

/**
 * Description:
 */
void timer1Start(void)
{
	TCCR1 |= gu8_Timer1prescale;
}

/**
 * Description:
 */
void timer1Stop(void)
{
	TCCR1 &= T1_NO_CLOCK;
}

/**
 * Description:
 * @param delay
 */
void timer1Delay_ms(uint16 delay)
{
	gu8_Timer1prescale = T1_PRESCALER_64;
	timer1Stop();
	timer1Set(65411);					// 65536-125 for 1 milli second
	timer1Start();
	
	while(delay)
	{
		while(!GET_BIT(TIFR,BIT2));			// bit 2 is tov1 flag of overflow
		SET_BIT(TIFR,BIT2);					// bit 2 is cleared by write a logic 1 to this bit
		timer1Set(65411);			// 65536-125 for 1 milli second
		delay--;
	}
	
}

/**
 * Description:
 * @param dutyCycle
 */
void timer1SwPWM(uint16 dutyCycle,uint16 freq)
{
	
	float dC = (dutyCycle/255.00);		// 65536 is the top of timer1 counter
	//gpioPinWrite(GPIOD,BIT4,HIGH);
	//gpioPinWrite(GPIOD,BIT5,HIGH);
	SET_BIT(PORTD_DATA,MOTOR_EN_1_BIT);
	SET_BIT(PORTD_DATA,MOTOR_EN_2_BIT);
	
	timer1Delay_ms(dC*freq);
	
	//gpioPinWrite(GPIOD,BIT4,LOW);
	//gpioPinWrite(GPIOD,BIT5,LOW);
	CLR_BIT(PORTD_DATA,MOTOR_EN_1_BIT);
	CLR_BIT(PORTD_DATA,MOTOR_EN_2_BIT);
	
	timer1Delay_ms((1-dC)*freq);
}


/*===========================Timer2 Control===============================*/
/**
 * Description:
 * @param control
 * @param initialValue
 * @param outputCompare
 * @param interruptMask
 * @param assynchronous // is use to activate assyncrounous function in ASSR register but not used here
 */
void timer2Init(En_timer2Mode_t mode,En_timer2OC_t OC,En_timer2perscaler_t prescal, uint8 initialValue, uint8 outputCompare, uint8 interruptMask)
{
	TCCR2 = mode | OC;
	TCNT2 = initialValue;
	OCR2 = outputCompare;
	
	TIMSK |= interruptMask;
	
	gu8_Timer2prescale = prescal;			
}
/**
 * Description:
 * @param value
 */
void timer2Set(uint8 value)
{
	TCNT2 = value;
}

/**
 * Description:
 * @return
 */
uint8 timer2Read(void)
{
	return TCNT2;
}

/**
 * Description:
 */
void timer2Start(void)
{
	TCCR2 |= gu8_Timer2prescale;
}

/**
 * Description:
 */
void timer2Stop(void)
{
	TCCR2 &= T2_NO_CLOCK;
}

/**
 * Description:
 * @param delay
 */
void timer2Delay_ms(uint16 delay)
{
	gu8_Timer2prescale = T2_PRESCALER_64;
	timer2Stop();
	timer2Set(130);				// 255-125 for 1 milli second
	timer2Start();
	
	while(delay)
	{
		while(!GET_BIT(TIFR,BIT6));
		SET_BIT(TIFR,BIT6);		// bit 6 is cleared by write a logic 1 to this bit
		timer2Set(130);			// 255-125 for 1 milli second
		delay--;
	}
	
	timer2Stop();
}

/**
 * Description:
 * @param dutyCycle
 */
void timer2SwPWM(uint8 dutyCycle,uint8 freq);

/*
 * user defined
 */
void timer2Delay_us(uint32 delay);