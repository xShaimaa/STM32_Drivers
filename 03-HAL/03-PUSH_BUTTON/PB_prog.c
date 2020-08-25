/*********************************************************************************/
/* Author    : Shimo	                                                         */
/* Version   : V01                                                               */
/* Date      : 17 Aug 2020                                                       */
/*********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"

#include "PB_private.h"
#include "PB_config.h"
#include "PB_interface.h"


/* struct to hold the push button data */
typedef struct
{
    u8 samples[2];
    PB_State_t state;
}PB_Info_t;

/* Global variables */
PB_Info_t  PB_info ;
PB_State_t PB_State;

/* configuring Push Button as input */
void PB_voidInit()
{
	/* initializing the clock for the corresponding port */
	RCC_voidEnableClock(RCC_APB2, PB_PORT);
	/* stting the pull configurations */
	#if (PB_INPUT_MODE == INTERNAL_PULL_UP) || (PB_INPUT_MODE == INTERNAL_PULL_DOWN)
		MGPIO_VoidSetPinDir(PB_PORT, PB_PIN, INPUT_PULL_UP_DOWN);
		
		#if	  (PB_INPUT_MODE == INTERNAL_PULL_UP)
		GPIO_voidSetPullMode(PB_PORT, PB_PIN, PULL_UP);
		
		#elif (PB_INPUT_MODE == INTERNAL_PULL_DOWN)
		GPIO_voidSetPullMode(PB_PORT, PB_PIN, PULL_DOWN);
		
		#endif

	#endif
	
	#if (PB_INPUT_MODE == EXTERNAL_PULL_UP) || (PB_INPUT_MODE == EXTERNAL_PULL_DOWN)
		GPIO_voidSetPinDir(PB_PORT, PB_PIN, INPUT_FLOATING);
	#endif	
	
	/* setting the voltage configurations passed on pull type*/
	#if   (PB_INPUT_MODE == INTERNAL_PULL_UP ) || (PB_INPUT_MODE == EXTERNAL_PULL_UP )
		#define PB_PRESS_VOLT   0
		#define PB_RELEASE_VOLT  1

	#elif (PB_INPUT_MODE == INTERNAL_PULL_DOWN) || (PB_INPUT_MODE == EXTERNAL_PULL_DOWN)
		#define PB_PRESS_VOLT   1
		#define PB_RELEASE_VOLT  0
	#endif

	/* setting the push button initial state */
	PB_info.state = RELEASED;
}


void PB_voidUpdate(void)
{	
	/* updating the samples */
	PB_info.samples[0] = PB_info.samples[1];
	PB_info.samples[1] = MGPIO_u8GetPinVal(PB_PORT, PB_PIN);
	
	switch(PB_State)
	{
		case RELEASED:
					if((PB_info.samples[0] == PB_PRESS_VOLT) &&
				       (PB_info.samples[1] == PB_PRESS_VOLT))
					{
						PB_info.state = PRE_PRESSED;
					}
					break;
		
		case PRE_PRESSED:
					if(PB_info.samples[1] == PB_PRESS_VOLT)
					{
						PB_info.state = PRESSED;
					}
					break;	
		
		case PRESSED:
					if((PB_info.samples[0] == PB_RELEASE_VOLT) &&
				       (PB_info.samples[1] == PB_RELEASE_VOLT))
					{
						PB_info.state = PRE_RELEASED;
					}
					break;
		
		case PRE_RELEASED:
					if(PB_info.samples[1] == PB_RELEASE_VOLT)
					{
						PB_info.state = PRESSED;
					}
					break;	
		
		default: 	break;
					
	}
}


PB_State_t PB_GetState(void)
{
	return (PB_info.state);
}
