/*********************************************************************************
 * 文件名  ：usart1.c
 * 描述    ：将printf函数重定向到USART1。这样就可以用printf函数将单片机的数据
 *           打印到PC上的超级终端或串口调试助手。         
 * 实验平台：STM32开发板
 * 硬件连接：------------------------
 *          | PA9  - USART1(Tx)      |
 *          | PA10 - USART1(Rx)      |
 *           ------------------------
 * 库版本  ：ST3.0.0
 *
**********************************************************************************/
#include "main.h"
#include "bsp_usart.h"
// #include <stdarg.h>
// #include "stm32f10x_tim.h"
// #include "misc.h"
// #include "stm32f10x_gpio.h"
// #include "stm32f10x_rcc.h"
// #include "stm32f10x_usart.h"

//  #include <stdio.h>

// #if 0
	
/*
 * 函数名：USART1_Config
 * 描述  ：USART1 GPIO 配置,工作模式配置
 * 输入  ：无
 * 输出  : 无
 * 调用  ：外部调用
 */
void USART1_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;

	/* config USART1 clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_GPIOA, ENABLE);

	/* USART1 GPIO config */
   /* Configure USART1 Tx (PA.09) as alternate function push-pull */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);    
  /* Configure USART1 Rx (PA.10) as input floating */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
	  
	/* USART1 mode config */
	USART_InitStructure.USART_BaudRate = 115200;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;//USART_Parity_No ;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(USART1, &USART_InitStructure); 
  USART_Cmd(USART1, ENABLE);
}

// int fputc(int ch, FILE *f)
// {
// /* 将Printf内容发往串口 */
// //  USART_SendData(USART1, (unsigned char) ch);
//  // while (!(USART1->SR & USART_FLAG_TXE));
 
//   return (ch);
// }

int fputc(int ch, FILE *f) {
  while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET){}
  USART_SendData(USART1, ch);
  return(ch);
}



// #endif




