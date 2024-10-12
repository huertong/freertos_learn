#ifndef __BSP_USART_H
#define	__BSP_USART_H

#include "stm32f10x.h"
#include <stdio.h>

//#define RS485_TR_0   RS485_TR0()     //??   PF.5       50?    PA4
//#define RS485_RCV_0  RS485_RCV0()    //??
//#define USART2_tx_en  RS485_USART_ITConfig_tx_en()    //??

//RS485串口相关宏定义
#define  RS485_USART                    USART2
#define  RS485_USART_IRQ                USART2_IRQn
#define  RS485_USART_IRQHandler         USART2_IRQHandler
#define  RS485_USART_CLK                RCC_APB1Periph_USART2  //USART2外设相关时钟
#define  RS485_USART_APBxClkCmd         RCC_APB1PeriphClockCmd  //启用/停止外设总线
//#define  RS485_USART_BAUDRATE           115200
#define  RS485_USART_GPIO_CLK           (RCC_APB2Periph_GPIOA)  //GPIO相关时钟
#define  RS485_USART_GPIO_APBxClkCmd    RCC_APB2PeriphClockCmd    
#define  RS485_USART_TX_GPIO_PORT       GPIOA  
#define  RS485_USART_TX_GPIO_PIN        GPIO_Pin_2  //发送引脚
#define  RS485_USART_RX_GPIO_PORT       GPIOA  
#define  RS485_USART_RX_GPIO_PIN        GPIO_Pin_3  //接收引脚
#define  RS485_USART_CK_GPIO_PORT       GPIOA  
#define  RS485_USART_CK_GPIO_PIN        GPIO_Pin_1  //收发控制引脚

//产生1ms时间，定时器相关宏定义
#define  OneMsTickTimer                 TIM3  //选择的定时器
//#define  OneMsTickTimer_Configuration   TIM3_Configuration 
#define  OneMsTickTimer_CLK             RCC_APB1Periph_TIM3  //定时器时钟
#define  OneMsTickTimer_APBxClkCmd      RCC_APB1PeriphClockCmd  //
#define  OneMsTickTimer_IRQ             TIM3_IRQn  //中断设定
#define  OneMsTickTimer_IRQHandler      TIM3_IRQHandler  //中断函数
#define  OneMsTickTimer_Period          1000 -1
#define  OneMsTickTimer_Prescaler       72-1

static unsigned int time_Cnt=0;    //时间计数1ms++，Get_SysTimeMs的返回参数

extern	unsigned char comio1;	
extern	unsigned char comio2;	

#define digitalToggle(p,i) {p->ODR ^=i;} //输出反转状态
//#define LED_TOGGLE		 digitalToggle(GPIOB,GPIO_Pin_3)

void USART1_Config(void);
int fputc(int ch, FILE *f);
void USART1_printf(USART_TypeDef* USARTx, uint8_t *Data,...);
void RS485_TR0();
void RS485_RCV0();
void RS485_USART_ITConfig_tx_en();

	
#endif /* __USART1_H */
