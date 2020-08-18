/*********************************************************************************/
/* Author    : Shimo	                                                         */
/* Version   : V01                                                               */
/* Date      : 17 Aug 2020                                                       */
/*********************************************************************************/
#ifndef PB_INTERFACE_H
#define PB_INTERFACE_H

typedef enum{	
		Released,
		Detected, 
		PreReleased,
		Update		
}PB_states_t;


/* public functions prototypes */

/******************************************************************************
* Description : configuring a push button as input
* Parameters  : none
* Return type : void
******************************************************************************/
void PB_voidInit();

/******************************************************************************
* Description : check the state of the push button
* Parameters  : none
* Return type : void                                                                           
*******************************************************************************/
void PB_voidCheckPB(void);

/******************************************************************************
* Description : check if a button is pressed
* Parameters  : none
* Return type : u8(the push button voltage)                                                                         
*******************************************************************************/
u8 PB_u8State(void);


#endif
