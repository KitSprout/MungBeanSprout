/*=====================================================================================================*/
/*=====================================================================================================*/
#include "drivers\stm32f0_system.h"
#include "modules\module_serial.h"

#include "beanSproutM_bsp.h"
/*=====================================================================================================*/
/*=====================================================================================================*/
void BSM_GPIO_Config( void )
{
  GPIO_InitTypeDef GPIO_InitStruct;

  /* Enable all GPIO Clk *******************************************************/
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);

  /* GPIO all analog input *****************************************************/
  GPIO_InitStruct.GPIO_Pin   = GPIO_Pin_All;
  GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_AN;
  GPIO_InitStruct.GPIO_OType = GPIO_OType_OD;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStruct.GPIO_PuPd  = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOB, &GPIO_InitStruct);
  GPIO_InitStruct.GPIO_Pin   = GPIO_Pin_All & (~(GPIO_Pin_13 | GPIO_Pin_14));
  GPIO_Init(GPIOA, &GPIO_InitStruct);
}
/*====================================================================================================*/
/*====================================================================================================*/
pFunc UART1_irqEven = NULL;
void BSM_UART_Config( pFunc pUARTx )
{
  UART1_irqEven = pUARTx;

  Serial_Config();
  printf("\fHello World!\r\n");
}
/*=====================================================================================================*/
/*=====================================================================================================*/
