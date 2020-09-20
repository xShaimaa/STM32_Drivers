/*********************************************************************************/
/* Author    : Shimo	                                                         */
/* Version   : V01                                                               */
/* Date      : 31 Aug 2020                                                       */
/*********************************************************************************/
#ifndef LEDMRX_INTERFACE_H
#define LEDMRX_INTERFACE_H


/* Public functions prototypes */

/******************************************************************************
* Description : initializing the LED Matrix
* Parameters  : void
* Return type : void
******************************************************************************/
void HLEDMRX_voidInit(void);

/******************************************************************************
* Description : Displaying data on the LED Matrix
* Parameters  : array of the columns values
* Return type : void
******************************************************************************/
void HLEDMRX_voidDisplay(u8 *Copy_u8Data);

/******************************************************************************
* Description : swaping data on the LED Matrix
* Parameters  : array of columns values, columns number
* Return type : void
******************************************************************************/
void HLEDMRX_voidSwap(u8 *Copy_u8arr, u8 Copy_u8ColsNum);



#endif
