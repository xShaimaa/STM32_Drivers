/*********************************************************************************/
/* Author    : Shimo	                                                         */
/* Version   : V01                                                               */
/* Date      : 13 Aug 2020                                                       */
/*********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"

#include "LED_private.h"
#include "LED_config.h"
#include "LED_interface.h"

/* configuring an LED as output */
void LED_voidInit(u8 Copy_u8PORT, u8 Copy_u8PIN)
{
	/* initializing the clock for the corresponding port */
	RCC_voidEnableClock(RCC_APB2, Copy_u8PORT);
	/* setting the pin as output */
	MGPIO_VoidSetPinDir(Copy_u8PORT, Copy_u8PIN, LED_OUTPUT_MODE);
	/* setting the initial value as LOW */
	MGPIO_VoidSetPinVal(Copy_u8PORT, Copy_u8PIN, GPIO_LOW);
}

/* control the state of an LED */
void LED_voidLEDVal(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Val)
{
	switch(Copy_u8Val)
	{
		case LED_ON : 	MGPIO_VoidSetPinVal(Copy_u8PORT, Copy_u8PIN, LED_MODE);		break;
		
		case LED_OFF: 	MGPIO_VoidSetPinVal(Copy_u8PORT, Copy_u8PIN, ~(LED_MODE));	break;
		
		case LED_TOG: 	MGPIO_VoidTogPin(Copy_u8PORT, Copy_u8PIN);					break;
		
		default 	:	 															break;
	}
}
