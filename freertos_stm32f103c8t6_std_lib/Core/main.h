#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

//注意头文件循环依赖问题
/* Includes ------------------------------------------------------------------*/
// #include <stdint.h>
#include <stdio.h>


#include "stm32f10x.h"
#include "system_stm32f10x.h"
#include "misc.h"
#include "stm32f10x_tim.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_usart.h"



#include "bsp_usart.h"


void Error_Handler(void);


#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
