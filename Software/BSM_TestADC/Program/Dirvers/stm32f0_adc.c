/*====================================================================================================*/
/*====================================================================================================*/
#include "stm32f0_system.h"
#include "stm32f0_adc.h"
/*====================================================================================================*/
/*====================================================================================================*/
static __IO uint16_t ADC_DMA_Buf[ADC_Sample][ADC_Channel] = {0};
/*====================================================================================================*/
/*====================================================================================================*
**函數 : ADC_Config
**功能 : ADC 配置
**輸入 : None
**輸出 : None
**使用 : ADC_Config();
**====================================================================================================*/
/*====================================================================================================*/
void ADC_Config( void )
{
  DMA_InitTypeDef DMA_InitStruct;
  ADC_InitTypeDef ADC_InitStruct;

  ADC_DeInit(ADC1);

  /* ADC Clk Init *************************************************************/
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);

  /* ADC DMA Init *************************************************************/
  DMA_DeInit(DMA1_Channel1);
  DMA_InitStruct.DMA_PeripheralBaseAddr = (uint32_t)ADC1_DR_ADDRESS;          // Peripheral address
  DMA_InitStruct.DMA_MemoryBaseAddr = (uint32_t)ADC_DMA_Buf;                  // Memory address
  DMA_InitStruct.DMA_DIR = DMA_DIR_PeripheralSRC;                             // Peripheral to Memory
  DMA_InitStruct.DMA_BufferSize = ADC_Channel*ADC_Sample;                     // Memory Buffer Size
  DMA_InitStruct.DMA_PeripheralInc = DMA_PeripheralInc_Disable;               // Peripheral address 遞增 Disable
  DMA_InitStruct.DMA_MemoryInc = DMA_MemoryInc_Enable;                        // Memory address 遞增 Enable
  DMA_InitStruct.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;    // Peripheral Data Size 16bit
  DMA_InitStruct.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;            // Memory Data Size 16bit
  DMA_InitStruct.DMA_Mode = DMA_Mode_Circular;                                // 循環模式 Enable
  DMA_InitStruct.DMA_Priority = DMA_Priority_Medium;                          // ADC DMA通道 普通優先級
  DMA_InitStruct.DMA_M2M = DMA_M2M_Disable;
  DMA_Init(DMA1_Channel1, &DMA_InitStruct);
  DMA_Cmd(DMA1_Channel1, ENABLE);

  /* ADC Init *****************************************************************/
  ADC_DMARequestModeConfig(ADC1, ADC_DMAMode_Circular);
  ADC_StructInit(&ADC_InitStruct);

  ADC_InitStruct.ADC_Resolution = ADC_Resolution_12b;                         // 解析度 12bit
  ADC_InitStruct.ADC_ContinuousConvMode = ENABLE;                             // 連續轉換模式
  ADC_InitStruct.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;    // 外部觸發 Disable
  ADC_InitStruct.ADC_DataAlign = ADC_DataAlign_Right;                         // ADC數據右對齊
  ADC_InitStruct.ADC_ScanDirection = ADC_ScanDirection_Upward;
  ADC_Init(ADC1, &ADC_InitStruct); 

  ADC_ChannelConfig(ADC1, ADC_Channel_0, ADC_SampleTime_55_5Cycles);
  ADC_ChannelConfig(ADC1, ADC_Channel_1, ADC_SampleTime_55_5Cycles);

  ADC_GetCalibrationFactor(ADC1);
  ADC_DMACmd(ADC1, ENABLE);
  ADC_Cmd(ADC1, ENABLE);     
  while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_ADRDY)); 
  ADC_StartOfConversion(ADC1);
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : ADC_Average
**功能 : 將 ADC 轉換後的資料取平均
**輸入 : *pADC_AveTr, AveSample
**輸出 : None
**使用 : ADC_Average(ADC_AveTr);
**====================================================================================================*/
/*====================================================================================================*/
void ADC_Average( uint16_t* pADC_AveTr )
{
  uint8_t i = 0, j = 0;;
  uint32_t ADC_DMA_Tmp[ADC_Channel] = {0};

  for(i=0; i<ADC_Channel; i++) {
    for(j=0; j<ADC_Sample; j++)
      ADC_DMA_Tmp[i] += ADC_DMA_Buf[j][i];
    pADC_AveTr[i] = (uint16_t)(ADC_DMA_Tmp[i] / ADC_Sample);
  }
}
/*====================================================================================================*/
/*====================================================================================================*/
