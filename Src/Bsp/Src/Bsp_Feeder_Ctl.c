#include "Bsp_Feeder_Ctl.h"

void Bsp_Feeder_Ctl_Init()
{
    GPIO_InitTypeDef GPIO_InitStruct;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    GPIO_InitStruct.GPIO_Pin = BSP_FEED_CTL_GPIO;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz; 

    GPIO_Init(GPIOB, &GPIO_InitStruct);
}

void Bsp_Feeder_Feed_Ctl()
{
    GPIO_SetBits(GPIOB, BSP_FEED_CTL_GPIO);

    delay_ms(1000);

    GPIO_ResetBits(GPIOB, BSP_FEED_CTL_GPIO);
}