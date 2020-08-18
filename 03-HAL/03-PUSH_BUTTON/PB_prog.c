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


/* data type to hold the push button state */
typedef enum{	
		Released,
		Detected, 
		PreReleased,
		Update		
}PB_states_t;

/* variables */
PB_states_t PB_State = Waiting;
u8 Temp_Press = PB_RELEASE_VOLT;
u8 PB_Press = PB_RELEASE_VOLT;
u8 PB_Count = 0;

/* configuring Push Button as input */
void PB_voidInit()
{
	MGPIO_VoidSetPinDir(PB_PORT, PB_PIN, PB_INPUT_MODE);
	GPIOA_BRR = (1<<1);	//pull down
}



void PB_voidCheckPB(void)
{	
	switch(PB_State)
	{
		case Released 	 :
						if(PB_PIN == PB_PRESS_VOLT)
						{
						 	PB_State = Detected;
							PB_Count = 0;
							Temp_Press = PB_PRESS_VOLT;
						}
						break;
		
		case Detected 	 :
						if(Temp_Press = PB_PRESS_VOLT)
						{
						 	PB_Count ++;
							if(PB_Count > PB_COUNT_CHECK)
							{
								PB_State = PreReleased;
							}
						}
						else
						{
							PB_State = Released;
						}
						break;
		
		case PreReleased :
						if(PB_PIN == PB_RELEASE_VOLT)
						{
						 	PB_State = Update;
						}
						break;
		
		case Update 	 :
						PB_Press = Temp_Press;        
						PB_State = Waiting;     
						PB_Count = 0;           
						Temp_Press = PB_RELEASE_VOLT;  
						break;        
		
		default 		 : 
						PB_State = Waiting;
						PB_Count = 0;
						Temp_Press = PB_RELEASE_VOLT;
						PB_Press = PB_RELEASE_VOLT;
						break;
	}
}


u8 PB_u8State(void)
{
	return(Temp_Press);
}