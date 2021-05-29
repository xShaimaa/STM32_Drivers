/*********************************************************************************/
/* Author    : Shimo	                                                         */
/* Version   : V02                                                               */
/* Date      : 11 Nov 2020                                                       */
/*********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "FPEC_private.h"
#include "FPEC_config.h"
#include "FPEC_interface.h"


void FPEC_voidInit(void)
{
	/* unlocking the flash using the unlock sequence */
	FPEC -> KEYR = KEY1;
	FPEC -> KEYR = KEY2;
}


void FPEC_voidUnlockOptionBytes(void)
{
	/* unlocking the option bytes using the unlock sequence */
	FPEC -> OPTKEYR = KEY1;
	FPEC -> OPTKEYR = KEY2;
}


void FPEC_voidLockOptionBytes(void)
{
	/* locking the option bytes, software reset */
    CLR_BIT(FPEC -> CR, OPTWRE);
}


void FPEC_voidLock(void)
{
	/* locking the flash memory, reset by hardware */
	SET_BIT(FPEC -> CR, LOCK);
}


u8 FPEC_voidProgramHalfWord(u16 Copy_u16Data, u32 Copy_u32Address)
{
	/* check whether FPEC is locked o not */
	if(GET_BIT(FPEC -> CR, LOCK))
	{
		/* Unlock sequence */
		FPEC -> KEYR = KEY1;
		FPEC -> KEYR = KEY2;
	}
	
	/* setting the PG bit */
	SET_BIT(FPEC -> CR, PG);
		
	/* perform half word data write on desired address */	
	*(volatile u16* Copy_u32Address) = Copy_u16Data;
	
	/* check that no flash memory operation is ongoing */
	while(GET_BIT(FPEC -> SR, BSY));
		
	/* verify the written data */
	if(*(volatile u16* Copy_u32Address) == Copy_u16Data)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
	/* clearing the PG bit */
	CLR_BIT(FPEC -> CR, PG);
}

void FPEC_voidProgramFlash(* Copy_u16Data, u8 Copy_u8Len, u32 Copy_u32Address)
{
	/* check whether FPEC is locked o not */
	if(GET_BIT(FPEC -> CR, LOCK))
	{
		/* Unlock sequence */
		FPEC -> KEYR = KEY1;
		FPEC -> KEYR = KEY2;
	}
	
	for(u8 i = 0; i < Copy_u8Len, i++)
	{
		/* setting the PG bit */
		SET_BIT(FPEC -> CR, PG);		
		/* perform half word data write on desired address */	
		*(volatile u16* Copy_u32Address) = Copy_u16Data[i];
		
		/* check that no flash memory operation is ongoing */
		while(GET_BIT(FPEC -> SR, BSY));
			
		/* setting the next address to be programed */	
		Copy_u32Address += 2;	
	}	
	
	/* clearing the PG bit */
	CLR_BIT(FPEC -> CR, PG);
}


u16 FPEC_u16ReadData(u16 *Copy_u16Address)
{
	return (*((volatile u16 *) Copy_u16Address));
}


void FPEC_voidErasePage(u32 Copy_u32Page)
{
	/* check whether FPEC is locked o not */
	if(GET_BIT(FPEC -> CR, LOCK))
	{
		/* Unlock sequence */
		FPEC -> KEYR = KEY1;
		FPEC -> KEYR = KEY2;
	}
	
	/* enable erasing */
	SET_BIT(FPEC -> CR, PER);
		
	/* selecting the page to be erased */
	FPEC -> AR = (START_ADDRRESS + (Copy_u32Page * PAGE_SIZE));
		
	/* set start bit */
	SET_BIT(FPEC -> CR, STRT); 

	/* check that no flash memory operation is ongoing */
	while(GET_BIT(FPEC -> SR, BSY));
		
	/* disable erasing */
	CLR_BIT(FPEC -> CR, PER);	
}