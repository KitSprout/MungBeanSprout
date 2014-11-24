/* #include "stm32f0_system.h" */

#ifndef __STM32F0_SYSTEM_H
#define __STM32F0_SYSTEM_H

#include "stm32f0xx.h"
#include "stm32f0_delay.h"
/*====================================================================================================*/
/*====================================================================================================*/
#define U8_MAX     ((uint8_t)255)
#define S8_MAX     ((int8_t)127)
#define S8_MIN     ((int8_t)-128)
#define U16_MAX    ((uint16_t)65535u)
#define S16_MAX    ((int16_t)32767)
#define S16_MIN    ((int16_t)-32768)
#define U32_MAX    ((uint32_t)4294967295uL)
#define S32_MAX    ((int32_t)2147483647)
#define S32_MIN    ((int32_t)-2147483648)

#define Byte32(Byte4, Byte3, Byte2, Byte1)  ((u32)((((uint8_t)(Byte4))<<24) | (((uint8_t)(Byte3))<<16) | (((uint8_t)(Byte2))<<8) | ((uint8_t)(Byte1))))
#define Byte16(ByteH, ByteL)  ((uint16_t)((((uint16_t)(ByteH))<<8) | ((uint16_t)(ByteL))))
#define Byte8H(ByteH)         ((uint8_t)(((uint16_t)(ByteH))>>8))
#define Byte8L(ByteL)         ((uint8_t)(ByteL))

#define NULL 0
/*====================================================================================================*/
/*====================================================================================================*/
#endif
