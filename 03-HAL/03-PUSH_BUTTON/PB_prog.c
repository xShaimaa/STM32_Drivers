/*********************************************************************************/
/* Author    : Shimo	                                                         */
/* Version   : V01                                                               */
/* Date      : 17 Aug 2020                                                       */
/*********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "DIO_private.h"

#include "PB_private.h"
#include "PB_config.h"
#include "PB_interface.h"


/* struct to hold the push button data */
typedef struct
{
    u8 samples[2];
    PB_State_t state;
}PB_Info_t;

PB_Info_t PB_Info; 

/* configuring Push Button as input */
void PB_voidInit()
{
	#if (PB_INPUT_MODE == INTERNAL_PULL_UP) || (PB_INPUT_MODE == INTERNAL_PULL_DOWN)
		GPIO_voidSetPinDir(PB_PORT, PB_PIN, INPUT_PULL_UP_DOWN);
		
		#if	  (PB_INPUT_MODE == INTERNAL_PULL_UP)
		GPIO_voidSetPullMode(PB_PORT, PB_PIN, PULL_UP);
		
		#elif (PB_INPUT_MODE == INTERNAL_PULL_DOWN)
		GPIO_voidSetPullMode(PB_PORT, PB_PIN, PULL_DOWN);
		
	#endif
	
	#if (PB_INPUT_MODE == EXTERNAL_PULL_UP) || (PB_INPUT_MODE == EXTERNAL_PULL_DOWN)
		GPIO_voidSetPinDir(PB_PORT, PB_PIN, INPUT_FLOATING);
	#endif	
	
	/* setting the initial state */	
	PB_Info.State = RELEASED; 
}


void PB_voidUpdate(void)
{	
	switch(PB_State)
	{
		case RELEASED:
						
		
		case PRE_PRESSED:
						
		
		case PRESSED:
						
		
		case PRE_RELEASED:
		
		default: 
					
	}
}


PB_states_t PB_GetState(void)
{
	return (PB_info.state) ;
}