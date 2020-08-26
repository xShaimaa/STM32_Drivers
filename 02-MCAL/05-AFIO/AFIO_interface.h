/*********************************************************************************/
/* Author    : Shimo	                                                         */
/* Version   : V01                                                               */
/* Date      : 26 Aug 2020                                                       */
/*********************************************************************************/
#ifndef AFIO_INTERFACE_H
#define AFIO_INTERFACE_H

/* public functions prototypes */

/******************************************************************************
* Description : setting the EXTI configurations
* Parameters  : Line number (0->15), PortMap
* Return type : void
******************************************************************************/
void MAFIO_voidSetEXTIConfig(u8 Copy_u8Line, u8 Copy_u8PortMap);

#endif
