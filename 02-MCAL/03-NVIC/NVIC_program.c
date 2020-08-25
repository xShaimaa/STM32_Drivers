/*********************************************************************************/
/* Author    : Shimo	                                                         */
/* Version   : V01                                                               */
/* Date      : 22 Aug 2020                                                       */
/*********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

/* initializes the interrupt group priority */
void MNVIC_voidInit(void)
{
	SCB_AIRCR = MNVIC_GROUP_SUB_DISTRIBUTION;
}

/* enabling the interrupt */
void MNVIC_voidEnableIRQ(u8 Copy_u8IRQNum)
{
	if (Copy_u8IRQNum <= 31)
	{
		NVIC_ISER0 = (1 << Copy_u8IRQNum);
	}
	
	else if (Copy_u8IRQNum <= 59)
	{
		Copy_u8IRQNum -= 32;
		NVIC_ISER1 = (1 << Copy_u8IRQNum);
	}
}

/* disabling the interrupt */
void MNVIC_voidDisableIRQ(u8 Copy_u8IRQNum)
{
	if (Copy_u8IRQNum <= 31)
	{
		NVIC_ICER0 = (1 << Copy_u8IRQNum);
	}
	
	else if (Copy_u8IRQNum <= 59)
	{
		Copy_u8IRQNum -= 32;
		NVIC_ICER1 = (1 << Copy_u8IRQNum);
	}
}

/* setting the interrupt's pending flag */
void MNVIC_voidSetPendingFlag(u8 Copy_u8IRQNum)
{
	if (Copy_u8IRQNum <= 31)
	{
		NVIC_ISPR0 = (1 << Copy_u8IRQNum);
	}
	
	else if (Copy_u8IRQNum <= 59)
	{
		Copy_u8IRQNum -= 32;
		NVIC_ISPR1 = (1 << Copy_u8IRQNum);
	}
}

/* clearing the interrupt's pending flag */
void MNVIC_voidClrPendingFlag(u8 Copy_u8IRQNum)
{
	if (Copy_u8IRQNum <= 31)
	{
		NVIC_ICPR0 = (1 << Copy_u8IRQNum);
	}
	
	else if (Copy_u8IRQNum <= 59)
	{
		Copy_u8IRQNum -= 32;
		NVIC_ICPR1 = (1 << Copy_u8IRQNum);
	}
}


/* getting the active flag statues */
u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IRQNum)
{
	u8 Local_u8Result;
	
	if (Copy_u8IRQNum <= 31)
	{
		Local_u8Result = GET_BIT(NVIC_IABR0,Copy_u8IRQNum);
	}
	
	else if (Copy_u8IRQNum <= 59)
	{
		Copy_u8IRQNum -= 32;
		Local_u8Result = GET_BIT(NVIC_IABR1,Copy_u8IRQNum);
	}
	
	return Local_u8Result;
}

/* setting the interrupt priority */
void MNVIC_voidSetPriorty(u8 Copy_u8IRQNum, u8 Copy_u8IRQPriority)
{
	if(Copy_u8IRQNum < 60)
	{
		NVIC_IPR[Copy_u8IRQNum] = (Copy_u8IRQPriority << 4);
	}
	
	else {
		/* error state */
	}
}
