#ifndef __BSP_USRAT_h
#define __BSP_USRAT_h

#include "stm32f10x_gpio.h"
#include "stm32f10x_usart.h"
#include "stm32f10x_rcc.h"

#define BSP_USART_TX		GPIO_Pin_9
#define BSP_USART_RX		GPIO_Pin_10
#define BSP_USART_BAUDRATE	115200

void Bsp_Usart_Send_Data(uint16_t SendData);

uint16_t Bsp_Usart_Recv_Data(uint16_t *RecvData);

void Bsp_Usart_Init(void);

#endif //__BSP_USRAT_h