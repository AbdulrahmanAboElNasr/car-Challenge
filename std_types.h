/*
 * std_types.h
 *
 * Created: 2019-12-03 2:49:34 PM
 *  Author: Abdo Sayed
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_


/************************************************************************/
/*                   typedefs for standard types                        */
/************************************************************************/

#define NULL	((void *)0)

typedef unsigned char uint8;
typedef unsigned int uint16;
typedef unsigned long int uint32;
typedef unsigned long long uint64;
typedef signed char sint8;
typedef signed int sint16;
typedef signed long int sint32;
typedef signed long long sint64;
typedef volatile uint8* const reg_type8;
typedef volatile uint16* const reg_type16;


/************************************************************************/
/*				 		defining boolean values                         */
/************************************************************************/
#define FALSE 	0	// defines boolean false
#define TRUE 	1	// defines boolean true


/************************************************************************/
/*						 LOW/HIGH defines                               */
/************************************************************************/
#define LOW  0		// defines LOW value for a bit
#define HIGH 1	// defines HIGH value for a bit


/************************************************************************/
/*						 BIT_MATH defines                               */
/************************************************************************/

/* Set Bit in specific register with 1 */
#define SET_BIT(Reg,BIT_NB) 		((Reg)|=(BIT_NB))
/* Set Bit in specific register with 0 */
#define CLR_BIT(Reg,BIT_NB) 		((Reg)&=~(BIT_NB))
/* Toggle Bit in specific register */
#define TOGGLE_BIT(Reg,BIT_NB) 		((Reg) ^= (BIT_NB))
/* Assign Bit in specific register with given value */
#define ASSIGN_BIT(Reg,BIT_NB,VAL)  (Reg) = ((( Reg & (~(BIT_NB)))|(Reg&BIT_NB)))
/* Get VARiable's Certin BIT Value */
#define GET_BIT(Reg,BIT_NB) 		(((Reg)&(BIT_NB))/(BIT_NB))




#endif /* STD_TYPES_H_ */