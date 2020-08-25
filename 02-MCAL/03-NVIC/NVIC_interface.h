/*********************************************************************************/
/* Author    : Shimo	                                                         */
/* Version   : V01                                                               */
/* Date      : 22 Aug 2020                                                       */
/*********************************************************************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

/* public functions prototypes */

/******************************************************************************
* Description : initializes the interrupt group priority
* Parameters  : void 
* Return type : void 
******************************************************************************/
void MNVIC_voidInit(void);

/******************************************************************************
* Description : enabling the interrupt
* Parameters  : Interrupt number (0 -> 59)
* Return type : void
******************************************************************************/
void MNVIC_voidEnableIRQ(u8 Copy_u8IRQNum);

/******************************************************************************
* Description : disabling the interrupt
* Parameters  : Interrupt number (0 -> 59)
* Return type : void
******************************************************************************/
void MNVIC_voidDisableIRQ(u8 Copy_u8IRQNum);

/******************************************************************************
* Description : setting the interrupt's pending flag
* Parameters  : Interrupt number (1 -> 59)
* Return type : void
******************************************************************************/
void MNVIC_voidSetPendingFlag(u8 Copy_u8IRQNum);

/******************************************************************************
* Description : clearing the interrupt's pending flag
* Parameters  : Interrupt number (0 -> 59)
* Return type : void
******************************************************************************/
void MNVIC_voidClrPendingFlag(u8 Copy_u8IRQNum);

/******************************************************************************
* Description : getting the active flag statues
* Parameters  : Interrupt number (0 -> 59)
* Return type : u8 (the active flag)
******************************************************************************/
u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IRQNum);

/******************************************************************************
* Description : setting the interrupt priority
* Parameters  : Interrupt number (0-> 59), Interrupt priority (0->15)
* Return type : void 
******************************************************************************/
void MNVIC_voidSetPriorty(u8 Copy_u8IRQNum, u8 Copy_u8IRQPriority);


#endif
