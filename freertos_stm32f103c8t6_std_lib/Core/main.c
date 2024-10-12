
/**FreeRTOS  + STM32 
 * @file main.c
 * @author fire
 * @version V1.0
 * @date 2018-xx-xx
 * @brief FreeRTOS  + STM32 
 *
 */

#include "main.h"
#include "FreeRTOS.h"
#include "task.h"
#include "FreeRTOSConfig.h"


uint32_t SystemCoreClock = 72000000;

static void BSP_Init(void)
{

//    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

    /* LED ??? */
//    LED_GPIO_Config();

    /* ????? */
//    USART_Config();
}


void vTaskLEDControl(void *pvParameters)
{
    // ���� LED �� GPIO
    // GPIO_Config(); // ���������� GPIO ���ú���

    while (1)
    {

        // ���� LED
        // HAL_GPIO_WritePin(GPIOx, GPIO_PIN_x, GPIO_PIN_SET); // �滻Ϊ��� GPIO ��������

        // �ȴ� 1 ��
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}


void vTaskPrintfTestControl(void *pvParameters)
{
    while (1){

        printf("LED11\n"); // ??printf??
        // fflush(stdout); // ȷ���������
        // �ȴ� 1 ��
        vTaskDelay(pdMS_TO_TICKS(1000));

        printf("LED2\n"); // ??printf??
        // fflush(stdout); // ȷ���������
        // �ȴ� 1 ��
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

int main(void)
{
    // ϵͳ��ʼ��
    SystemInit();
    USART1_Config();
    printf("Hello1\n"); // ??printf??
    printf("Hello2\n"); // ??printf??

    // ���� LED ��������
    // xTaskCreate(vTaskLEDControl, "LED Task", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);

   // ���� LED ��������
    if (xTaskCreate(vTaskPrintfTestControl, "PRINTF Task", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 2, NULL) != pdPASS)
    {
        printf("Task creation failed!\n");
    }

    xTaskCreate(vTaskLEDControl, "LED Task", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 2, NULL);

    printf("��ʼ���õ�����\n");
    // ����������
    vTaskStartScheduler();

    printf("���õ��Ⱥ�\n");//���������

    // ���һ��������������Զ���ᵽ������
    for(;;);
}

















