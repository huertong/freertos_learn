#ifndef __BSP_USART_H
#define	__BSP_USART_H

#include "stm32f10x.h"
#include <stdio.h>

//#define RS485_TR_0   RS485_TR0()     //??   PF.5       50?    PA4
//#define RS485_RCV_0  RS485_RCV0()    //??
//#define USART2_tx_en  RS485_USART_ITConfig_tx_en()    //??

//RS485������غ궨��
#define  RS485_USART                    USART2
#define  RS485_USART_IRQ                USART2_IRQn
#define  RS485_USART_IRQHandler         USART2_IRQHandler
#define  RS485_USART_CLK                RCC_APB1Periph_USART2  //USART2�������ʱ��
#define  RS485_USART_APBxClkCmd         RCC_APB1PeriphClockCmd  //����/ֹͣ��������
//#define  RS485_USART_BAUDRATE           115200
#define  RS485_USART_GPIO_CLK           (RCC_APB2Periph_GPIOA)  //GPIO���ʱ��
#define  RS485_USART_GPIO_APBxClkCmd    RCC_APB2PeriphClockCmd    
#define  RS485_USART_TX_GPIO_PORT       GPIOA  
#define  RS485_USART_TX_GPIO_PIN        GPIO_Pin_2  //��������
#define  RS485_USART_RX_GPIO_PORT       GPIOA  
#define  RS485_USART_RX_GPIO_PIN        GPIO_Pin_3  //��������
#define  RS485_USART_CK_GPIO_PORT       GPIOA  
#define  RS485_USART_CK_GPIO_PIN        GPIO_Pin_1  //�շ���������

//����1msʱ�䣬��ʱ����غ궨��
#define  OneMsTickTimer                 TIM3  //ѡ��Ķ�ʱ��
//#define  OneMsTickTimer_Configuration   TIM3_Configuration 
#define  OneMsTickTimer_CLK             RCC_APB1Periph_TIM3  //��ʱ��ʱ��
#define  OneMsTickTimer_APBxClkCmd      RCC_APB1PeriphClockCmd  //
#define  OneMsTickTimer_IRQ             TIM3_IRQn  //�ж��趨
#define  OneMsTickTimer_IRQHandler      TIM3_IRQHandler  //�жϺ���
#define  OneMsTickTimer_Period          1000 -1
#define  OneMsTickTimer_Prescaler       72-1

static unsigned int time_Cnt=0;    //ʱ�����1ms++��Get_SysTimeMs�ķ��ز���

extern	unsigned char comio1;	
extern	unsigned char comio2;	

#define digitalToggle(p,i) {p->ODR ^=i;} //�����ת״̬
//#define LED_TOGGLE		 digitalToggle(GPIOB,GPIO_Pin_3)

void USART1_Config(void);
int fputc(int ch, FILE *f);
void USART1_printf(USART_TypeDef* USARTx, uint8_t *Data,...);
void RS485_TR0();
void RS485_RCV0();
void RS485_USART_ITConfig_tx_en();

	
#endif /* __USART1_H */
