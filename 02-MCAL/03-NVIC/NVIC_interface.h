/*********************************************************************************/
/* Author    : Shimo	                                                         */
/* Version   : V01                                                               */
/* Date      : 22 Aug 2020                                                       */
/*********************************************************************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

/* Valid external interrupts */

#define	WWDG_IRQ 			 0
#define	TAMPER_IRQ 			 1
#define	RTC_IRQ 			 2
#define	FLASH_IRQ 			 3
#define	RCC_IRQ 			 4
#define	EXTI0_IRQ 			 5
#define	EXTI1_IRQ 			 6
#define	EXTI2_IRQ 			 7
#define	EXTI3_IRQ 			 8
#define	EXTI4_IRQ 			 9
#define	DMA1_Channel1_IRQ 	10
#define	DMA1_Channel2_IRQ 	11
#define	DMA1_Channel3_IRQ 	12
#define	DMA1_Channel4_IRQ 	13
#define	DMA1_Channel5_IRQ 	14
#define	DMA1_Channel6_IRQ 	15
#define	DMA1_Channel7_IRQ 	16
#define	ADC1_2_IRQ 			17
#define	CAN1_TX_IRQ 		18
#define	CAN1_RX0_IRQ 		19
#define	CAN1_RX1_IRQ 		20
#define	CAN1_SCE_IRQ 		21
#define	EXTI9_5_IRQ 		22
#define	TIM1_BRK_IRQ 		23
#define	TIM1_UP_IRQ 		24
#define	TIM1_TRG_COM_IRQ 	25
#define	TIM1_CC_IRQ 		26
#define	TIM2_IRQ 			27
#define	TIM3_IRQ 			28
#define	TIM4_IRQ 			29
#define	I2C1_EV_IRQ 		30
#define	I2C1_ER_IRQ 		31
#define	I2C2_EV_IRQ 		32
#define	I2C2_ER_IRQ 		33
#define	SPI1_IRQ 			34
#define	SPI2_IRQ 			35
#define	USART1_IRQ 			36
#define	USART2_IRQ 			37
#define	USART3_IRQ 			38
#define	EXTI15_10_IRQ 		39
#define	RTCAlarm_IRQ 		40
#define	USBWakeup_IRQ 		41 
#define	TIM8_BRK_IRQ 		42
#define	TIM8_UP_IRQ 		43
#define	TIM8_TRG_COM_IRQ 	44
#define	TIM8_CC_IRQ 		45
#define	ADC3_IRQ 			46
#define	FSMC_IRQ 			47
#define	SDIO_IRQ 			48
#define	TIM5_IRQ 			49
#define	SPI3_IRQ 			50
#define	UART4_IRQ 			51
#define	UART5_IRQ 			52
#define	TIM6_IRQ 			53
#define	TIM7_IRQ 			54
#define	DMA2_Channel1_IRQ 	55
#define	DMA2_Channel2_IRQ 	56
#define	DMA2_Channel3_IRQ 	57
#define	DMA2_Channel4_5_IRQ 58


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
void MNVIC_voidEnableIRQ(u8 Copy_u8IRQName);

/******************************************************************************
* Description : disabling the interrupt
* Parameters  : IRQ name
* Return type : void
******************************************************************************/
void MNVIC_voidDisableIRQ(u8 Copy_u8IRQName);

/******************************************************************************
* Description : setting the interrupt's pending flag
* Parameters  : IRQ name
* Return type : void
******************************************************************************/
void MNVIC_voidSetPendingFlag(u8 Copy_u8IRQName);

/******************************************************************************
* Description : clearing the interrupt's pending flag
* Parameters  : IRQ name
* Return type : void
******************************************************************************/
void MNVIC_voidClrPendingFlag(u8 Copy_u8IRQName);

/******************************************************************************
* Description : getting the active flag statues
* Parameters  : IRQ name
* Return type : u8 (the active flag)
******************************************************************************/
u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IRQName);

/******************************************************************************
* Description : setting the interrupt priority
* Parameters  : IRQ name, Interrupt priority (0->15)
* Return type : void 
******************************************************************************/
void MNVIC_voidSetPriorty(u8 Copy_u8IRQName, u8 Copy_u8IRQPriority);


#endif
