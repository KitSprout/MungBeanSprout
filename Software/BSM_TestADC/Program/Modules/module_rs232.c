/*====================================================================================================*/
/*====================================================================================================*/
#include "stm32f0_system.h"
#include "stm32f0_usart.h"
#include "module_rs232.h"
/*====================================================================================================*/
/*====================================================================================================*/
#define USARTx                USART1
#define USARTx_CLK            RCC_APB2Periph_USART1

#define USARTx_TX_PIN         GPIO_Pin_9
#define USARTx_TX_GPIO_PORT   GPIOA
#define USARTx_TX_GPIO_CLK    RCC_AHBPeriph_GPIOA
#define USARTx_TX_SOURCE      GPIO_PinSource9
#define USARTx_TX_AF          GPIO_AF_1

#define USARTx_RX_PIN         GPIO_Pin_10
#define USARTx_RX_GPIO_PORT   GPIOA
#define USARTx_RX_GPIO_CLK    RCC_AHBPeriph_GPIOA
#define USARTx_RX_SOURCE      GPIO_PinSource10
#define USARTx_RX_AF          GPIO_AF_1

#define USARTx_BAUDRATE       115200
#define USARTx_BYTESIZE       USART_WordLength_8b
#define USARTx_STOPBITS       USART_StopBits_1
#define USARTx_PARITY         USART_Parity_No
#define USARTx_HARDWARECTRL   USART_HardwareFlowControl_None
/*====================================================================================================*/
/*====================================================================================================*
**函數 : RS232_Config
**功能 : RS232 配置
**輸入 : None
**輸出 : None
**使用 : RS232_Config();
**====================================================================================================*/
/*====================================================================================================*/
void RS232_Config( void )
{
  GPIO_InitTypeDef GPIO_InitStruct;
  USART_InitTypeDef USART_InitStruct;

  /* UART Clk Init *************************************************************/
  RCC_APB2PeriphClockCmd(USARTx_CLK, ENABLE);
  RCC_AHBPeriphClockCmd(USARTx_TX_GPIO_CLK | USARTx_RX_GPIO_CLK, ENABLE);

  GPIO_PinAFConfig(USARTx_TX_GPIO_PORT, USARTx_TX_SOURCE, USARTx_TX_AF);
  GPIO_PinAFConfig(USARTx_RX_GPIO_PORT, USARTx_RX_SOURCE, USARTx_RX_AF);

  /* USARTx Tx PA9 */
  GPIO_InitStruct.GPIO_Pin = USARTx_TX_PIN;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(USARTx_TX_GPIO_PORT, &GPIO_InitStruct);
  /* USARTx Rx PA10 */
  GPIO_InitStruct.GPIO_Pin = USARTx_RX_PIN;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(USARTx_RX_GPIO_PORT, &GPIO_InitStruct);

  /* UART Init *****************************************************************/
  USART_InitStruct.USART_BaudRate = USARTx_BAUDRATE;
  USART_InitStruct.USART_WordLength = USARTx_BYTESIZE;
  USART_InitStruct.USART_StopBits = USARTx_STOPBITS;
  USART_InitStruct.USART_Parity = USARTx_PARITY;
  USART_InitStruct.USART_HardwareFlowControl = USARTx_HARDWARECTRL;
  USART_InitStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
  USART_Init(USARTx, &USART_InitStruct);
  USART_Cmd(USARTx, ENABLE);

  USART_ClearFlag(USARTx, USART_FLAG_TC);
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : RS232_SendStr
**功能 : 發送字串
**輸入 : *pWord
**輸出 : None
**使用 : RS232_SendStr((uint8_t*)"Hellow World!");
**====================================================================================================*/
/*====================================================================================================*/
void RS232_SendStr( uint8_t *pWord )
{
  while(*pWord != '\0') {
    UART_SendByte(USARTx, *pWord);
    pWord++;
  }
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : RS232_SendNum
**功能 : 將數值轉字串發送
**輸入 : Type, NumLen, SendData
**輸出 : None
**使用 : RS232_SendNum(Type_O, 6, 1024);
**====================================================================================================*/
/*====================================================================================================*/
void RS232_SendNum( StrType Type, uint8_t NumLen, int32_t SendData )
{
  uint8_t TrData[32] = {0};
  uint8_t *pWord = TrData;

  Str_NumToChar(Type, NumLen, TrData, SendData);

  while(*pWord != '\0') {
    UART_SendByte(USARTx, *pWord);
    pWord++;
  }
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : RS232_SendData
**功能 : 發送資料
**輸入 : *SendData, DataLen
**輸出 : None
**使用 : RS232_SendData(SendData, DataLen);
**====================================================================================================*/
/*====================================================================================================*/
void RS232_SendData( uint8_t *SendData, uint16_t DataLen )
{
  UART_SendData(USARTx, SendData, DataLen);
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : RS232_RecvStr
**功能 : 接收字串
**輸入 : *pWord
**輸出 : None
**使用 : RS232_RecvStr(RecvStirng);
**====================================================================================================*/
/*====================================================================================================*/
void RS232_RecvStr( uint8_t *pWord )
{
  do {
    *pWord = UART_RecvByte(USARTx);
    pWord++;
  } while(*(pWord-1) != '\0');
  *pWord = '\0';
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : RS232_RecvData
**功能 : 接收資料
**輸入 : *RecvData, DataLen
**輸出 : None
**使用 : RS232_RecvData(RecvData, DataLen);
**====================================================================================================*/
/*====================================================================================================*/
void RS232_RecvData( uint8_t *RecvData, uint16_t DataLen )
{
  UART_RecvData(USARTx, RecvData, DataLen);
}
/*====================================================================================================*/
/*====================================================================================================*/
