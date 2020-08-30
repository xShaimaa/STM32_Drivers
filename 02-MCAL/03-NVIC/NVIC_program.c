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
void MNVIC_voidEnableIRQ(IRQ_t Copy_u8IRQName)
{
	if (Copy_u8IRQName <= 31)
	{
		NVIC_ISER0 = (1 << Copy_u8IRQName);
	}
	
	else if (Copy_u8IRQName <= 59)
	{
		Copy_u8IRQName -= 32;
		NVIC_ISER1 = (1 << Copy_u8IRQName);
	}
}

/* disabling the interrupt */
void MNVIC_voidDisableIRQ(IRQ_t Copy_u8IRQName)
{
	if (Copy_u8IRQName <= 31)
	{
		NVIC_ICER0 = (1 << Copy_u8IRQName);
	}
	
	else if (Copy_u8IRQName <= 59)
	{
		Copy_u8IRQName -= 32;
		NVIC_ICER1 = (1 << Copy_u8IRQName);
	}
}

/* setting the interrupt's pending flag */
void MNVIC_voidSetPendingFlag(IRQ_t Copy_u8IRQName)
{
	if (Copy_u8IRQName <= 31)
	{
		NVIC_ISPR0 = (1 << Copy_u8IRQName);
	}
	
	else if (Copy_u8IRQName <= 59)
	{
		Copy_u8IRQName -= 32;
		NVIC_ISPR1 = (1 << Copy_u8IRQName);
	}
}

/* clearing the interrupt's pending flag */
void MNVIC_voidClrPendingFlag(IRQ_t Copy_u8IRQName)
{
	if (Copy_u8IRQName <= 31)
	{
		NVIC_ICPR0 = (1 << Copy_u8IRQName);
	}
	
	else if (Copy_u8IRQName <= 59)
	{
		Copy_u8IRQName -= 32;
		NVIC_ICPR1 = (1 << Copy_u8IRQName);
	}
}


/* getting the active flag statues */
u8 MNVIC_u8GetActiveFlag(IRQ_t Copy_u8IRQName)
{
	u8 Local_u8Result;
	
	if (Copy_u8IRQName <= 31)
	{
		Local_u8Result = GET_BIT(NVIC_IABR0, Copy_u8IRQName);
	}
	
	else if (Copy_u8IRQName <= 59)
	{
		Copy_u8IRQName -= 32;
		Local_u8Result = GET_BIT(NVIC_IABR1, Copy_u8IRQName);
	}
	
	return Local_u8Result;
}

/* setting the interrupt priority */
void MNVIC_voidSetPriorty(IRQ_t Copy_u8IRQName, u8 Copy_u8IRQPriority)
{
	if(Copy_u8IRQName < 60)
	{
		NVIC_IPR[Copy_u8IRQName] = (Copy_u8IRQPriority << 4);
	}
	
	else {
		/* error state */
	}
}
