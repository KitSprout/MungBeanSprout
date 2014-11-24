/* #include "stm32f0_usart.h" */

#ifndef __STM32F0_USART_H
#define __STM32F0_USART_H

#include "stm32f0xx.h"
/*====================================================================================================*/
/*====================================================================================================*/
void    UART_SendByte( USART_TypeDef *USARTx, uint8_t SendData );
uint8_t UART_RecvByte( USART_TypeDef *USARTx );
void    UART_SendData( USART_TypeDef *USARTx, uint8_t *SendData, uint16_t DataLen );
void    UART_RecvData( USART_TypeDef *USARTx, uint8_t *RecvData, uint16_t DataLen );
/*====================================================================================================*/
/*====================================================================================================*/
#endif	 
