/*********************************************************************************/
/* Author    : Shimo	                                                         */
/* Version   : V01                                                               */
/* Date      : 19 Sep 2020                                                       */
/*********************************************************************************/
#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H

/* Registers Definitions */

typedef struct
{
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 CR3;
	volatile u32 GRPR;
}USART_t;

#define USART ((volatile USART_t *)0x40013800)

#endif 