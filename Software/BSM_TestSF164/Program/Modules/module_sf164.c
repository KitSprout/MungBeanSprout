/*====================================================================================================*/
/*====================================================================================================*/
#include "stm32f0_system.h"
#include "module_sf164.h"
/*====================================================================================================*/
/*====================================================================================================*/
#define SF164_DSA_PIN        GPIO_Pin_0
#define SF164_DSA_GPIO_PORT  GPIOA
#define SF164_DSA_GPIO_CLK   RCC_AHBPeriph_GPIOA
#define SF164_DSA_H          GPIO_SetBits(SF164_DSA_GPIO_PORT, SF164_DSA_PIN)
#define SF164_DSA_L          GPIO_ResetBits(SF164_DSA_GPIO_PORT, SF164_DSA_PIN)

#define SF164_DSB_PIN        GPIO_Pin_1
#define SF164_DSB_GPIO_PORT  GPIOA
#define SF164_DSB_GPIO_CLK   RCC_AHBPeriph_GPIOA
#define SF164_DSB_H          GPIO_SetBits(SF164_DSB_GPIO_PORT, SF164_DSB_PIN)
#define SF164_DSB_L          GPIO_ResetBits(SF164_DSB_GPIO_PORT, SF164_DSB_PIN)

#define SF164_MR_PIN        GPIO_Pin_2
#define SF164_MR_GPIO_PORT  GPIOA
#define SF164_MR_GPIO_CLK   RCC_AHBPeriph_GPIOA
#define SF164_MR_H          GPIO_SetBits(SF164_MR_GPIO_PORT, SF164_MR_PIN)
#define SF164_MR_L          GPIO_ResetBits(SF164_MR_GPIO_PORT, SF164_MR_PIN)

#define SF164_CP_PIN        GPIO_Pin_3
#define SF164_CP_GPIO_PORT  GPIOA
#define SF164_CP_GPIO_CLK   RCC_AHBPeriph_GPIOA
#define SF164_CP_H          GPIO_SetBits(SF164_CP_GPIO_PORT, SF164_CP_PIN)
#define SF164_CP_L          GPIO_ResetBits(SF164_CP_GPIO_PORT, SF164_CP_PIN)
/*====================================================================================================*/
/*====================================================================================================*
**函數 : SF164_Config
**功能 : 74HC164 Config
**輸入 : None
**輸出 : None
**使用 : SF164_Config();
**====================================================================================================*/
/*====================================================================================================*/
void SF164_Config( void )
{
  GPIO_InitTypeDef GPIO_InitStruct;


  /* GPIO Clk Init *************************************************************/
  RCC_AHBPeriphClockCmd(SF164_DSA_GPIO_CLK, ENABLE);
  RCC_AHBPeriphClockCmd(SF164_DSB_GPIO_CLK, ENABLE);
  RCC_AHBPeriphClockCmd(SF164_MR_GPIO_CLK,  ENABLE);
  RCC_AHBPeriphClockCmd(SF164_CP_GPIO_CLK,  ENABLE);

  GPIO_InitStruct.GPIO_Pin = SF164_DSA_PIN;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(SF164_DSA_GPIO_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.GPIO_Pin = SF164_DSB_PIN;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(SF164_DSB_GPIO_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.GPIO_Pin = SF164_MR_PIN;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(SF164_MR_GPIO_PORT, &GPIO_InitStruct);

  GPIO_InitStruct.GPIO_Pin = SF164_CP_PIN;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(SF164_CP_GPIO_PORT, &GPIO_InitStruct);

  SF164_Reset();

  SF164_DSA_L;
  SF164_DSB_L;
  SF164_MR_H;
  SF164_CP_L;
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : SF164_Reset
**功能 : Reset 74HC164
**輸入 : None
**輸出 : None
**使用 : SF164_Reset();
**====================================================================================================*/
/*====================================================================================================*/
void SF164_Reset( void )
{
  SF164_MR_L;
  Delay_1ms(1);
  SF164_MR_H;
  Delay_1ms(1);
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : SF164_Shift
**功能 : Shift bit
**輸入 : SendData
**輸出 : None
**使用 : SF164_Shift(1);
**====================================================================================================*/
/*====================================================================================================*/
void SF164_Shift( uint8_t SendData )
{
  SF164_CP_L;
  if(SendData & 0x01) {
    SF164_DSA_H;
    SF164_DSB_H;
  }
  else {
    SF164_DSA_L;
    SF164_DSB_L;
  }
  SF164_CP_H;
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : SF164_SendByte
**功能 : Shift 8 bits
**輸入 : SendData
**輸出 : None
**使用 : SF164_SendByte(SendData);
**====================================================================================================*/
/*====================================================================================================*/
void SF164_SendByte( uint8_t SendData )
{
  uint8_t i = 0;

  for(i=0; i<8; i++) {
    SF164_CP_L;
    if(SendData & (0x80>>i)) {
      SF164_DSA_H;
      SF164_DSB_H;
    }
    else {
      SF164_DSA_L;
      SF164_DSB_L;
    }
    SF164_CP_H;
  }
}
/*====================================================================================================*/
/*====================================================================================================*/
