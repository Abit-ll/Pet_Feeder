#include "Main.h"

int main()
{
	uint16_t buff[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	uint16_t i;
	/* 串口及其他外设初始化 */
	SystemInit();

	Bsp_Usart_Init();

	for(i = 0; i < 10; i++)
		Bsp_Usart_Send_Data(buff[i]);

	while(1)
	{
		wifi_uart_service();
	}

	return 0;
}