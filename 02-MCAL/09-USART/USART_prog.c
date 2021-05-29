/*********************************************************************************/
/* Author    : Shimo	                                                         */
/* Version   : V01                                                               */
/* Date      : 19 Sep 2020                                                       */
/*********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_private.h"
#include "USART_config.h"
#include "USART_interface.h"

void MUSART1_voidInit(void)
{
	/* seting the Baud rate */
	/* 9600   -> BRR = 0x341 */
	USART -> BRR = 0x341;
	
	/* 115200 -> BRR = */
	
	/* Enable RX */
	SET_BIT((USART -> CR1),  2);
	
	/* Enable TX */
	SET_BIT((USART -> CR1),  3);
	
	/* Enable USART */
	SET_BIT((USART -> CR1), 13);
	
	/* clear te status reg */
	USART -> SR = 0;
}


void MUSART1_voidTransmit(u8 arr[])
{
	u8 i = 0;
	while(arr[i] != '\0')
	{
		USART -> DR = arr[i];
		
		/* wait till transmission is complete */
		while(GET_BIT((USART -> SR), 6) == 0);
		i++;
	}
}


void MUSART1_u8Receive(void)
{
	/* wait for data to be received */
	while(GET_BIT((USART -> SR), 5) == 0);
	
	/* return the first 16 bit */
	return (0xFF & (USART -> DR));
}

