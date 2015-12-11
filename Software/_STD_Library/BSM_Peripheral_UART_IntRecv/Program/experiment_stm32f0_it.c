/*====================================================================================================*/
/*====================================================================================================*/
#include "stm32f0_system.h"
#include "experiment_stm32f0.h"
#include "module_rs232.h"
/*====================================================================================================*/
/*====================================================================================================*/
void USART1_IRQHandler( void )
{
  uint8_t RecvData = 0;

  if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET) {
    RecvData = RS232_RecvByte();
    if(RecvData == 0x0D)
      RS232_SendStr((int8_t*)"\r\n");
    else
      RS232_SendByte(RecvData);
  }
  USART_ClearFlag(USART1, USART_IT_RXNE);
}
/*====================================================================================================*/
/*====================================================================================================*/
void NMI_Handler( void ) { while(1); }
void HardFault_Handler( void ) { while(1); }
void SVC_Handler( void ) { while(1); }
void PendSV_Handler( void ) { while(1); }
/*====================================================================================================*/
/*====================================================================================================*/
//void SysTick_Handler( void );
//void WWDG_IRQHandler( void );
//void RTC_IRQHandler( void );
//void FLASH_IRQHandler( void );
//void RCC_IRQHandler( void );
//void EXTI0_1_IRQHandler( void );
//void EXTI2_3_IRQHandler( void );
//void EXTI4_15_IRQHandler( void );
//void DMA1_Channel1_IRQHandler( void );
//void DMA1_Channel2_3_IRQHandler( void );
//void DMA1_Channel4_5_IRQHandler( void );
//void ADC1_IRQHandler( void );
//void TIM1_BRK_UP_TRG_COM_IRQHandler( void );
//void TIM1_CC_IRQHandler( void );
//void TIM3_IRQHandler( void );
//void TIM14_IRQHandler( void );
//void TIM15_IRQHandler( void );
//void TIM16_IRQHandler( void );
//void TIM17_IRQHandler( void );
//void I2C1_IRQHandler( void );
//void I2C2_IRQHandler( void );
//void SPI1_IRQHandler( void );
//void SPI2_IRQHandler( void );
//void USART1_IRQHandler( void );
//void USART2_IRQHandler( void );
/*====================================================================================================*/
/*====================================================================================================*/
