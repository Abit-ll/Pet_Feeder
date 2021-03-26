#include "Bsp_Usart.h"

void Bsp_Usart_Send_Data(USART_TypeDef* USART, uint16_t SendData)
{
	USART_SendData(USART, SendData);
	while(USART_GetFlagStatus(USART, USART_FLAG_TXE) == RESET);
}

uint16_t Bsp_Usart_Recv_Data(USART_TypeDef* USART, uint16_t *RecvData)
{
	if(USART_GetFlagStatus(USART, USART_FLAG_RXNE) == RESET)
		return 0;
	*RecvData = USART_ReceiveData(USART);

	return 1;
}

void Bsp_Usart_Init(USART_Struct Usart)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	USART_InitTypeDef USART_InitStruct;
	NVIC_InitTypeDef NVIC_InitSturct;

	if(Usart == Bsp_Debug_Usart)
	{
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_USART1, ENABLE);

		GPIO_InitStruct.GPIO_Pin = BSP_DEBUG_USART_TX;
		GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
		GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOA, &GPIO_InitStruct);

		GPIO_InitStruct.GPIO_Pin = BSP_DEBUG_USART_RX;
		GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
		GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOA, &GPIO_InitStruct);

		USART_InitStruct.USART_BaudRate = BSP_DEBUG_USART_BAUDRATE;
		USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
		USART_InitStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
		USART_InitStruct.USART_Parity = USART_Parity_No;
		USART_InitStruct.USART_StopBits = USART_StopBits_1;
		USART_InitStruct.USART_WordLength = USART_WordLength_8b;
		USART_Init(BSP_DEBUG_USART, &USART_InitStruct);
		USART_Cmd(BSP_DEBUG_USART, ENABLE);
	}

	if(Usart == Bsp_SDK_Usart)
	{
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);

		GPIO_InitStruct.GPIO_Pin = BSP_SDK_USART_TX;
		GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
		GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOA, &GPIO_InitStruct);

		GPIO_InitStruct.GPIO_Pin = BSP_SDK_USART_RX;
		GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
		GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOA, &GPIO_InitStruct);

		USART_InitStruct.USART_BaudRate = BSP_SDK_USART_BAUDRATE;
		USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
		USART_InitStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
		USART_InitStruct.USART_Parity = USART_Parity_No;
		USART_InitStruct.USART_StopBits = USART_StopBits_1;
		USART_InitStruct.USART_WordLength = USART_WordLength_8b;
		USART_Init(BSP_SDK_USART, &USART_InitStruct);
		USART_Cmd(BSP_SDK_USART, ENABLE);

		USART_ITConfig(BSP_SDK_USART, USART_IT_RXNE, ENABLE);
		NVIC_InitSturct.NVIC_IRQChannel = USART2_IRQn;
		NVIC_InitSturct.NVIC_IRQChannelCmd = ENABLE;
		NVIC_InitSturct.NVIC_IRQChannelPreemptionPriority = 3;
		NVIC_InitSturct.NVIC_IRQChannelSubPriority = 3;
		NVIC_Init(&NVIC_InitSturct);
	}
}