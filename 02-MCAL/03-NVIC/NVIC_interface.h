/*********************************************************************************/
/* Author    : Shimo	                                                         */
/* Version   : V01                                                               */
/* Date      : 22 Aug 2020                                                       */
/*********************************************************************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

/* Data type holding external interrupts */
typedef enum{
		WWDG_IRQ = 0,
		TAMPER_IRQ,
		RTC_IRQ,
		FLASH_IRQ,
		RCC_IRQ,
		EXTI0_IRQ,
		EXTI1_IRQ,
		EXTI2_IRQ,
		EXTI3_IRQ,
		EXTI4_IRQ,
		DMA1_Channel1_IRQ,
		DMA1_Channel2_IRQ,
		DMA1_Channel3_IRQ,
		DMA1_Channel4_IRQ,
		DMA1_Channel5_IRQ,
		DMA1_Channel6_IRQ,
		DMA1_Channel7_IRQ,
		ADC1_2_IRQ,
		CAN1_TX_IRQ,
		CAN1_RX0_IRQ,
		CAN1_RX1_IRQ,
		CAN1_SCE_IRQ,
		EXTI9_5_IRQ,
		TIM1_BRK_IRQ,
		TIM1_UP_IRQ,
		TIM1_TRG_COM_IRQ,
		TIM1_CC_IRQ,
		TIM2_IRQ,
		TIM3_IRQ,
		TIM4_IRQ,
		I2C1_EV_IRQ,
		I2C1_ER_IRQ,
		I2C2_EV_IRQ,
		I2C2_ER_IRQ,
		SPI1_IRQ,
		SPI2_IRQ,
		USART1_IRQ,
		USART2_IRQ,
		USART3_IRQ,
		EXTI15_10_IRQ,
		RTCAlarm_IRQ,
		USBWakeup_IRQ,
		TIM8_BRK_IRQ,
		TIM8_UP_IRQ,
		TIM8_TRG_COM_IRQ,
		TIM8_CC_IRQ,
		ADC3_IRQ,
		FSMC_IRQ,
		SDIO_IRQ,
		TIM5_IRQ,
		SPI3_IRQ,
		UART4_IRQ,
		UART5_IRQ,
		TIM6_IRQ,
		TIM7_IRQ,
		DMA2_Channel1_IRQ,
		DMA2_Channel2_IRQ,
		DMA2_Channel3_IRQ,
		DMA2_Channel4_5_IRQ
}IRQ_t


/* public functions prototypes */

/******************************************************************************
* Description : initializes the interrupt group priority
* Parameters  : void 
* Return type : void 
******************************************************************************/
void MNVIC_voidInit(void);

/******************************************************************************
* Description : enabling the interrupt
* Parameters  : IRQ name
* Return type : void
******************************************************************************/
void MNVIC_voidEnableIRQ(IRQ_t Copy_u8IRQName);

/******************************************************************************
* Description : disabling the interrupt
* Parameters  : IRQ name
* Return type : void
******************************************************************************/
void MNVIC_voidDisableIRQ(IRQ_t Copy_u8IRQName);

/******************************************************************************
* Description : setting the interrupt's pending flag
* Parameters  : IRQ name
* Return type : void
******************************************************************************/
void MNVIC_voidSetPendingFlag(IRQ_t Copy_u8IRQName);

/******************************************************************************
* Description : clearing the interrupt's pending flag
* Parameters  : IRQ name
* Return type : void
******************************************************************************/
void MNVIC_voidClrPendingFlag(IRQ_t Copy_u8IRQName);

/******************************************************************************
* Description : getting the active flag statues
* Parameters  : IRQ name
* Return type : u8 (the active flag)
******************************************************************************/
u8 MNVIC_u8GetActiveFlag(IRQ_t Copy_u8IRQName);

/******************************************************************************
* Description : setting the interrupt priority
* Parameters  : IRQ name, Interrupt priority (0->15)
* Return type : void 
******************************************************************************/
void MNVIC_voidSetPriorty(IRQ_t Copy_u8IRQName, u8 Copy_u8IRQPriority);


#endif
