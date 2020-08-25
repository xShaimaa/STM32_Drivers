/*********************************************************************************/
/* Author    : Shimo	                                                         */
/* Version   : V01                                                               */
/* Date      : 23 Aug 2020                                                       */
/*********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

void MEXTI_voidEnableEXTI(u8 Copy_u8Line, u8 Copy_u8IRQEvent)
{
	/* unmasking the IRQ line */
	SET_BIT(EXTI -> EXTI_IMR, Copy_u8Line);
	/* setting the eent configurations */
	switch(Copy_u8IRQEvent)
	{
		case EXTI_RISING_EDGE	:
						/* enabling the rising trigger and disabling the falling trigger*/
						SET_BIT(EXTI -> EXTI_RTSR, Copy_u8Line);
						CLR_BIT(EXTI ->	EXTI_FTSR, Copy_u8Line);
						break;
						
		case EXTI_FALLING_EDGE	:
						/* enabling the rising trigger and disabling the falling trigger*/
						SET_BIT(EXTI -> EXTI_FTSR, Copy_u8Line);
						CLR_BIT(EXTI ->	EXTI_RTSR, Copy_u8Line);
						break;
						
		case EXTI_ON_CHANGE		:
						/* enabling both the rising and the falling trigger*/
						SET_BIT(EXTI -> EXTI_FTSR, Copy_u8Line);
						SET_BIT(EXTI ->	EXTI_RTSR, Copy_u8Line);
						break;
						
		default		:	break;
	}
}

void MEXTI_voidDisableEXTI(u8 Copy_u8Line)
{
	/* masking the IRQ line */
	CLR_BIT(EXTI -> EXTI_IMR, copy_u8Line); 
}


void MEXTI_voidEnableSW(u8 Copy_u8Line)
{
	SET_BIT(EXTI -> EXTI_SWIER, SET_BIT(EXTI -> EXTI_IMR, Copy_u8Line));
}
