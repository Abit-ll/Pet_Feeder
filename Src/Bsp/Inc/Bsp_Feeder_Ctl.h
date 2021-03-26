#ifndef __BSP_FEEDER_CTL_H
#define __BSP_FEEDER_CTL_H

#include "misc.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"

#define BSP_FEED_CTL_GPIO       GPIO_Pin_1

extern void Bsp_Feeder_Ctl_Init();
extern void Bsp_Feeder_Feed_Ctl();

#endif //__BSP_FEEDER_CTL_H