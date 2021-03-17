#include "Bsp_Usart.h"

void Bsp_Usart_Send_Data(uint16_t SendData)
{
	USART_SendData(USART1, SendData);
	while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
}

uint16_t Bsp_Usart_Recv_Data(uint16_t *RecvData)
{
	if(USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET)
		return 0;
	*RecvData = USART_ReceiveData(USART1);

	return 1;
}

void Bsp_Usart_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	USART_InitTypeDef USART_InitStruct;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_USART1, ENABLE);

	GPIO_InitStruct.GPIO_Pin = BSP_USART_TX;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin = BSP_USART_RX;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStruct);

	USART_InitStruct.USART_BaudRate = BSP_USART_BAUDRATE;
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_InitStruct.USART_Parity = USART_Parity_No;
	USART_InitStruct.USART_StopBits = USART_StopBits_1;
	USART_InitStruct.USART_WordLength = USART_WordLength_8b;
	USART_Init(USART1, &USART_InitStruct);
	USART_Cmd(USART1, ENABLE);
}