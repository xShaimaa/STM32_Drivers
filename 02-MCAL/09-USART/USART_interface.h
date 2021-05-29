/*********************************************************************************/
/* Author    : Shimo	                                                         */
/* Version   : V01                                                               */
/* Date      : 19 Sep 2020                                                       */
/*********************************************************************************/
#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H


/* Public Functions Prototypes */

/******************************************************************************
* Description : 
* Parameters  : void
* Return type : void
******************************************************************************/
void MUSART1_voidInit(void);

void MUSART1_voidTransmit(u8 arr[]);

u8 MUSART1_u8Receive(void);





#endif
