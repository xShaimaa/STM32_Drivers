/*********************************************************************************/
/* Author    : Shimo	                                                         */
/* Version   : V01                                                               */
/* Date      : 14 Sep 2020                                                       */
/*********************************************************************************/
#ifndef STP_INTERFACE_H
#define STP_INTERFACE_H


/* Public Functions Prototypes */

/******************************************************************************
* Description : initializing the STP
* Parameters  : void
* Return type : void
******************************************************************************/
void STP_voidInit(void);

/******************************************************************************
* Description : sending synchronous data to the STP
* Parameters  : u8 (data to be sent)
* Return type : void
******************************************************************************/
void STP_voidSendSynch(u8 Copy_u8DataToSend);



#endif
