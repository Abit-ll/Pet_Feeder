#include "Main.h"

void delay_ms(u16 time);

int main()
{
	uint16_t i;
	uint16_t ret;

	/* 串口及其他外设初始化 */
	SystemInit();

	Bsp_Usart_Init(Bsp_Debug_Usart);
	Bsp_Usart_Init(Bsp_SDK_Usart);
	Bsp_Feeder_Ctl_Init();

	wifi_protocol_init();

	while(1)
	{
		wifi_uart_service();

		ret = mcu_get_wifi_work_state();
		printf("ret = 0x%x\r\n", ret);

		/* 获取SDK的联网状态， */
		if(mcu_get_wifi_work_state() != WIFI_CONN_CLOUD)
		{
			if(mcu_get_wifimode_flag() != SET_WIFICONFIG_SUCCESS)
			{
				/* MCU设置模组配网 */
				mcu_reset_wifi();
				mcu_set_wifi_mode(SMART_CONFIG);
				delay_ms(5000);
			}
		}

		delay_ms(2000);
	}

	return 0;
}

void delay_ms(u16 time)

{    

   u16 i=0;  

   while(time--)

   {
      i=12000;  //自己定义

      while(i--);
   }

}