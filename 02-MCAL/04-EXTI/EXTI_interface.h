/*********************************************************************************/
/* Author    : Shimo	                                                         */
/* Version   : V01                                                               */
/* Date      : 23 Aug 2020                                                       */
/*********************************************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H


/* interrupt events */
#define	EXTI_RISING_EDGE  0
#define	EXTI_FALLING_EDGE 1
#define	EXTI_ON_CHANGE	  2


/* public functions prototypes */

/******************************************************************************
* Description : enabling the external interrupt for a line and setting the corresponding event
* Parameters  : Line number (0->15), IRQ event type (Rising or falling edge or on change)
* Return type : void 
******************************************************************************/
void MEXTI_voidEnableEXTI(u8 Copy_u8Line, u8 Copy_u8IRQEvent);

/******************************************************************************
* Description : disabling the external interrupt for a line
* Parameters  : Line number (0->15) 
* Return type : void 
******************************************************************************/
void MEXTI_voidDisableEXTI(u8 Copy_u8Line);

/******************************************************************************
* Description : setting the software external interrupt for a line
* Parameters  : Line number (0->15) 
* Return type : void 
******************************************************************************/
void MEXTI_voidEnableSW(u8 Copy_u8Line);



#endif
