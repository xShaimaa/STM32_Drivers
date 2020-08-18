/*********************************************************************************/
/* Author    : Shimo	                                                         */
/* Version   : V01                                                               */
/* Date      : 13 Aug 2020                                                       */
/*********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"

#include "SSD_config.h"
#include "SSD_interface.h"

/* Global variables */
u8 SSD[10]		= {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
u8 SSD_Pins[7]  = {SSD_A, SSD_B, SSD_C, SSD_D, SSD_E, SSD_F, SSD_G};
u8 i = 0;

/* initializing the SSD as output */
void SSD_voidInit()
{
	RCC_voidEnableClock(RCC_APB2, SSD_PORT);
	for(i = 0; i<8; i++)
	{
		MGPIO_VoidSetPinDir(SSD_PORT, SSD_Pins[i], SSD_OUTPUT_MODE);
	}
}

/* displaying a number on an SSD */
void SSD_voidDisplay(u8 Copy_u8Num)
{
	#if (SSD_COM == COM_CATHOD)
		MGPIO_voidSetPinsFrom(SSD_PORT, SSD_Pins[0], SSD[Copy_u8Num]);

	#elif (SSD_COM == COM_ANOD)
		MGPIO_voidSetPinsFrom(SSD_PORT, SSD_Pins[0], ~(SSD[Copy_u8Num]));

	#endif
}