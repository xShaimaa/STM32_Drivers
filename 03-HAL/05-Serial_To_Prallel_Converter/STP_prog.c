/*********************************************************************************/
/* Author    : Shimo	                                                         */
/* Version   : V01                                                               */
/* Date      : 14 Sep 2020                                                       */
/*********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "MSTK_interface.h"

#include "STP_private.h"
#include "STP_config.h"
#include "STP_interface.h"

/* initialiing the STP pins */
void STP_voidInit(void)
{
	MGPIO_VoidSetPinDir(STP_SERIAL_DATA, OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDir(STP_SHIFT_CLK  , OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDir(STP_STORE_CLK  , OUTPUT_SPEED_2MHZ_PP);	
}


/* sending synchronous data to the STP */
void STP_voidSendSynch(u8 Copy_u8DataToSend)
{
	/* local variables */
	s8 Loc_s8Counter;
	u8 Loc_u8Bit;
	
	for(Loc_u8Counter = 7; Loc_u8Counter >= 0; Loc_u8Counter--)
	{
		/* send bit by bit, starting from MSb */
		Loc_u8Bit = GET_BIT(Copy_u8DataToSend, Loc_s8Counter);
		MGPIO_VoidSetPinVal(STP_SERIAL_DATA, Loc_u8Bit);
		
		/* sending 5us pulse to shift clk pin */
		MGPIO_VoidSetPinVal(STP_SHIFT_CLK, GPIO_HIGH);
		MSTK_voidSetBusyWait(5);
		MGPIO_VoidSetPinVal(STP_SHIFT_CLK, GPIO_LOW);
		MSTK_voidSetBusyWait(5);
	}
	/* sending 5us pulse to store clk pin */
	MGPIO_VoidSetPinVal(STP_STORE_CLK, GPIO_HIGH);
	MSTK_voidSetBusyWait(5);
	MGPIO_VoidSetPinVal(STP_STORE_CLK, GPIO_LOW);
	MSTK_voidSetBusyWait(5);
}
