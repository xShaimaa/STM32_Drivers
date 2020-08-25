/*********************************************************************************/
/* Author    : Shimo	                                                         */
/* Version   : V01                                                               */
/* Date      : 12 Aug 2020                                                       */
/*********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"

/* setting the pin mode */
void MGPIO_VoidSetPinDir(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Mode)
{
	switch(Copy_u8PORT)
	{
		case GPIOA :
					if(Copy_u8PIN <= 7)
					{
						GPIOA_CRL &= ~((0b1111) << (Copy_u8PIN * 4));
						GPIOA_CRL |=  ((Copy_u8Mode) << (Copy_u8PIN * 4)); 
					}
					else if(Copy_u8PIN <= 15)
					{
						Copy_u8PIN -= 8;
						GPIOA_CRH &= ~((0b1111) << (Copy_u8PIN * 4));
						GPIOA_CRH |=  ((Copy_u8Mode) << (Copy_u8PIN * 4)); 
					}
					break;
					
		case GPIOB :
					if(Copy_u8PIN <= 7)
					{
						GPIOB_CRL &= ~((0b1111) << (Copy_u8PIN * 4)); 
						GPIOB_CRL |=  ((Copy_u8Mode) << (Copy_u8PIN * 4)); 
					}
					else if(Copy_u8PIN <= 15)
					{
						Copy_u8PIN -= 8;
						GPIOB_CRH &= ~((0b1111) << (Copy_u8PIN * 4)); 
						GPIOB_CRH |=  ((Copy_u8Mode) << (Copy_u8PIN * 4)); 
					}
					break;
					
		case GPIOC :
					if(Copy_u8PIN <= 7)
					{
						GPIOC_CRL &= ~((0b1111) << (Copy_u8PIN * 4)); 
						GPIOC_CRL |=  ((Copy_u8Mode) << (Copy_u8PIN * 4)); 
					}
					else if(Copy_u8PIN <= 15)
					{
						Copy_u8PIN -= 8;
						GPIOC_CRH &= ~((0b1111) << (Copy_u8PIN * 4)); 
						GPIOC_CRH |=  ((Copy_u8Mode) << (Copy_u8PIN * 4)); 
					}
					break;
					
		default	:	break;
	}
}

/* setting a pin value */
void MGPIO_VoidSetPinVal(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Val)
{
	switch(Copy_u8PORT)
	{
		case GPIOA :
					if(Copy_u8Val == GPIO_HIGH)
					{
						GPIOA_BSRR = (1 << Copy_u8PIN);

					}
					else if(Copy_u8Val == GPIO_LOW)
					{
						GPIOA_BRR = (1 << Copy_u8PIN);
					}
					break;
					
		case GPIOB :
					if(Copy_u8Val == GPIO_HIGH)
					{
						GPIOB_BSRR = (1 << Copy_u8PIN);
					}
					else if(Copy_u8Val == GPIO_LOW)
					{
						GPIOB_BRR = (1 << Copy_u8PIN);
					}
					break;
					
		case GPIOC :
					if(Copy_u8Val == GPIO_HIGH)
					{
						GPIOC_BSRR = (1 << Copy_u8PIN);
					}
					else if(Copy_u8Val == GPIO_LOW)
					{
						GPIOC_BRR = (1 << Copy_u8PIN);
					}
					break;
					
		default	:	break;
	}
}

/* setting the pin pull mode*/
void GPIO_voidSetPullMode (u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8PullMode)
{
	switch (Copy_u8PORT) {
		case GPIOA :
			if(Copy_u8PullMode == PULL_UP){
				GPIOA_BSRR = (1 << Copy_u8PIN);
			}
			
			else if (Copy_u8PullMode == PULL_DOWN ){
				GPIOA_BRR = (1 << Copy_u8PIN);
			}
			break ;
		
		case GPIOB :
			if      (Copy_u8PullMode == PULL_UP){
				GPIOB_BSRR = (1 << Copy_u8PIN);
			}
			
			else if (Copy_u8PullMode == PULL_DOWN ){
				GPIOB_BRR  = (1 << Copy_u8PIN);
			}
			break ;
			
		case GPIOC :
			if      (Copy_u8PullMode == PULL_UP){
				GPIOC_BSRR = (1 << Copy_u8PIN);
			}
			
			else if (Copy_u8PullMode == PULL_DOWN ){
				GPIOC_BRR = (1 << Copy_u8PIN);
			}
			break ;
			
		default    :  break ;
	}
}


/* setting multiple pins value */
void MGPIO_voidSetPinsFrom(u8 Copy_u8PORT, u8 Copy_u8PIN, u8 Copy_u8Val)
{
	switch(Copy_u8PORT)
	   {
	         case GPIOA :
	         GPIOA_ODR = (Copy_u8Val << Copy_u8PIN);
	         break;
	         case GPIOB :
	         GPIOB_ODR = (Copy_u8Val << Copy_u8PIN);
	         break;
	         case GPIOC :
	         GPIOC_ODR = (Copy_u8Val << Copy_u8PIN);
	         break;
	   }
}

/* toggling a pin */
void MGPIO_VoidTogPin(u8 Copy_u8PORT, u8 Copy_u8PIN)
{
	switch(Copy_u8PORT)
	{
		case GPIOA :
					TOG_BIT(GPIOA_ODR, Copy_u8PIN);
					break;

		case GPIOB :
					TOG_BIT(GPIOB_ODR, Copy_u8PIN);
					break;

		case GPIOC :
					TOG_BIT(GPIOC_ODR, Copy_u8PIN);
					break;

		default	:	break;
	}
}

/* reading a pin value S*/
u8 MGPIO_u8GetPinVal(u8 Copy_u8PORT, u8 Copy_u8PIN)
{
	u8 LOC_u8Result = 0;
	
	switch(Copy_u8PORT)
	{
		case GPIOA :	LOC_u8Result = GET_BIT(GPIOA_IDR, Copy_u8PIN);	break;
					
		case GPIOB :	LOC_u8Result = GET_BIT(GPIOB_IDR, Copy_u8PIN);	break;
					
		case GPIOC :	LOC_u8Result = GET_BIT(GPIOC_IDR, Copy_u8PIN);	break;

					
		default	:	break;
	}
	return LOC_u8Result;
}

/* locking the config */
/*void MGPIO_VoidLockPin(u8 Copy_u8PORT, u8 Copy_u8PIN)
{
	
}*/

