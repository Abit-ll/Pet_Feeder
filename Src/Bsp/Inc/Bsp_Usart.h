#ifndef __BSP_USRAT_h
#define __BSP_USRAT_h

#include "misc.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_usart.h"
#include "stm32f10x_rcc.h"
#include "stdio.h"	

#define BSP_DEBUG_USART                 USART1
#define BSP_DEBUG_USART_TX              GPIO_Pin_9
#define BSP_DEBUG_USART_RX              GPIO_Pin_10
#define BSP_DEBUG_USART_BAUDRATE        115200

#define BSP_SDK_USART                   USART2
#define BSP_SDK_USART_TX                GPIO_Pin_2
#define BSP_SDK_USART_RX                GPIO_Pin_3
#define BSP_SDK_USART_BAUDRATE          9600

typedef enum{
    Bsp_Debug_Usart = 0,
    Bsp_SDK_Usart,
    Bsp_Usart_Cnt,
} USART_Struct;

void Bsp_Usart_Send_Data(USART_TypeDef* USART, uint16_t SendData);

uint16_t Bsp_Usart_Recv_Data(USART_TypeDef* USART, uint16_t *RecvData);

void Bsp_Usart_Init(USART_Struct Usart);

#endif //__BSP_USRAT_h