/*********************************************************************************/
/* Author    : Shimo	                                                         */
/* Version   : V02                                                               */
/* Date      : 11 Nov 2020                                                       */
/*********************************************************************************/
#ifndef FPEC_INTERFACE_H
#define FPEC_INTERFACE_H


/* Public Functions Prototypes */

/******************************************************************************
* Description : unlocking the flash memory
* Parameters  : void
* Return type : void
******************************************************************************/
void FPEC_voidInit(void);

/******************************************************************************
* Description : unlocking the option keys
* Parameters  : void
* Return type : void
******************************************************************************/
void FPEC_voidUnlockOptionBytes(void);

/******************************************************************************
* Description : locking the option bytes
* Parameters  : void
* Return type : void
******************************************************************************/
void FPEC_voidLockOptionBytes(void);

/******************************************************************************
* Description : locking the flash memory
* Parameters  : void
* Return type : void
******************************************************************************/
void FPEC_voidLock(void);

/******************************************************************************
* Description : write half word on specific address
* Parameters  : data to be written, address to write on
* Return type : 1(successful write), 0(error)
******************************************************************************/
u8 FPEC_voidProgramHalfWord(u16 Copy_u16Data, u32 Copy_u32Address);

/******************************************************************************
* Description : write data from specific address
* Parameters  : data to be written, data length, address to start write from
* Return type : void
******************************************************************************/
void FPEC_voidProgramFlash(* Copy_u16Data, u8 Copy_u8Len, u32 Copy_u32Address);

/******************************************************************************
* Description : reading data from an address
* Parameters  : address to read data from
* Return type : u16 (the required data)
******************************************************************************/
u16 FPEC_u16ReadData(u16 *Copy_u16Address);

/******************************************************************************
* Description : erase one page from specific address
* Parameters  : address to erase the page from
* Return type : void
******************************************************************************/
void FPEC_voidErasePage(u32 Copy_u32Address);




#endif
