/*=====================================================================================================*/
/*=====================================================================================================*/
#include "drivers\stm32f0_system.h"

#include "beanSproutM.h"
/*=====================================================================================================*/
/*=====================================================================================================*/
void BSM_Init( void )
{
  BSM_GPIO_Config();
}
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

void BSM_Loop( void )
{
  while(1) {
    GPIO_A_Set();
    GPIO_B_Set();
    delay_ms(100);
    GPIO_A_Reset();
    GPIO_B_Reset();
    delay_ms(100);
  }
}
/*=====================================================================================================*/
/*=====================================================================================================*/
