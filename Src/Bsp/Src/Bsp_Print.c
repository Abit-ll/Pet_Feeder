#include "Bsp_Usart.h"

//////////////////////////////////////////////////////////////////
//加入以下代码,支持printf函数,而不需要选择use MicroLIB	  
#if 1
#pragma import(__use_no_semihosting)             
//标准库需要的支持函数                 
struct __FILE 
{ 
	int handle; 
}; 

FILE __stdout;       
//定义_sys_exit()以避免使用半主机模式    
void _sys_exit(int x) 
{ 
	x = x; 
} 
//重定义fputc函数 
int fputc(int ch, FILE *f)
{ 	
    while(USART_GetFlagStatus(BSP_DEBUG_USART, USART_FLAG_TXE) == RESET);
    USART_SendData(BSP_DEBUG_USART, ch);    
	return ch;
}
#endif