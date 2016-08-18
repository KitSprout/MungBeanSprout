/*=====================================================================================================*/
/*=====================================================================================================*/
#include "drivers\stm32f0_system.h"

#include "beanSproutM_bsp.h"
/*=====================================================================================================*/
/*=====================================================================================================*/
#define GPIO_A_PINs       GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_9 | GPIO_Pin_10
#define GPIO_A_GPIO_PORT  GPIOA
#define GPIO_A_Set()      GPIO_SetBits(GPIO_A_GPIO_PORT, GPIO_A_PINs)
#define GPIO_A_Reset()    GPIO_ResetBits(GPIO_A_GPIO_PORT, GPIO_A_PINs)

#define GPIO_B_PINs       GPIO_Pin_1
#define GPIO_B_GPIO_PORT  GPIOB
#define GPIO_B_Set()      GPIO_SetBits(GPIO_B_GPIO_PORT, GPIO_B_PINs)
#define GPIO_B_Reset()    GPIO_ResetBits(GPIO_B_GPIO_PORT, GPIO_B_PINs)

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

  /* GPIO Pin ******************************************************************/
  GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_OUT;
  GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStruct.GPIO_PuPd  = GPIO_PuPd_NOPULL;

  GPIO_InitStruct.GPIO_Pin   = GPIO_A_PINs;
  GPIO_Init(GPIO_A_GPIO_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.GPIO_Pin   = GPIO_B_PINs;
  GPIO_Init(GPIO_B_GPIO_PORT, &GPIO_InitStruct);

  /* GPIO Reset Pin ************************************************************/
  GPIO_A_Reset();
  GPIO_B_Reset();
}
/*=====================================================================================================*/
/*=====================================================================================================*/
