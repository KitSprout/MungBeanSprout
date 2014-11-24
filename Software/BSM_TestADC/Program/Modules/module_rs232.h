/* #include "module_rs232.h" */

#ifndef __MODULE_RS232_H
#define __MODULE_RS232_H

#include "stm32f0xx.h"
#include "algorithm_string.h"
/*====================================================================================================*/
/*====================================================================================================*/
void RS232_Config( void );
void RS232_SendStr( uint8_t *pWord );
void RS232_SendNum( StrType Type, uint8_t NumLen, int32_t SendData );
void RS232_SendData( uint8_t *SendData, uint16_t DataLen );
void RS232_RecvStr( uint8_t *pWord );
void RS232_RecvData( uint8_t *RecvData, uint16_t DataLen );
/*====================================================================================================*/
/*====================================================================================================*/
#endif
