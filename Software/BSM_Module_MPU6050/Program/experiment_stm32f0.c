/*=====================================================================================================*/
/*=====================================================================================================*/
#include "stm32f0_system.h"
#include "experiment_stm32f0.h"
#include "module_mpu6050.h"
/*=====================================================================================================*/
/*=====================================================================================================*/
#define LED_ON    GPIO_ResetBits(GPIOB, GPIO_Pin_1)
#define LED_OFF   GPIO_SetBits(GPIOB, GPIO_Pin_1)

int main( void )
{
  GPIO_Config();
  MPU6050_Init();

  LED_ON;
  Delay_100ms(1);
  LED_OFF;
  Delay_100ms(1);

  while(MPU6050_GetDeviceID() != MPU6050_Device_ID);

  while(1) {
    LED_ON;
    Delay_100ms(1);
    LED_OFF;
    Delay_100ms(1);
  }
}
/*=====================================================================================================*/
/*=====================================================================================================*/
void GPIO_Config( void )
{
  GPIO_InitTypeDef  GPIO_InitStruct; 

  /* GPIO Clk Init *************************************************************/
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);

  GPIO_InitStruct.GPIO_Pin =  GPIO_Pin_1;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStruct.GPIO_OType = GPIO_OType_OD;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOB, &GPIO_InitStruct);
}
/*=====================================================================================================*/
/*=====================================================================================================*/
