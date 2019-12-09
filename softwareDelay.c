/*
 * softwareDelay.c
 *
 * Created: 2019-12-03 9:33:36 PM
 *  Author: Abdo Sayed
 */ 
#include "softwareDelay.h"


/**
 * Description: this delay function operate in a polling manner
 * 				don't use it with RTOSs
 * @param n: the milli-seconds
 */
void SwDelay_ms(uint32 n)
{
	uint32 i,j;
	for (i=0 ; i<n ; i++ )		//n is number of milli-seconds;
	{
		for (j=0 ; j<1000 ; j++);	//for loop to measure 1 Milli-second
	}
}