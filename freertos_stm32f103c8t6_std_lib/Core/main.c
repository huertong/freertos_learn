
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
    // 配置 LED 的 GPIO
    // GPIO_Config(); // 这里调用你的 GPIO 配置函数

    while (1)
    {

        // 点亮 LED
        // HAL_GPIO_WritePin(GPIOx, GPIO_PIN_x, GPIO_PIN_SET); // 替换为你的 GPIO 引脚配置

        // 等待 1 秒
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}


void vTaskPrintfTestControl(void *pvParameters)
{
    while (1){

        printf("LED11\n"); // ??printf??
        // fflush(stdout); // 确保立即输出
        // 等待 1 秒
        vTaskDelay(pdMS_TO_TICKS(1000));

        printf("LED2\n"); // ??printf??
        // fflush(stdout); // 确保立即输出
        // 等待 1 秒
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

int main(void)
{
    // 系统初始化
    SystemInit();
    USART1_Config();
    printf("Hello1\n"); // ??printf??
    printf("Hello2\n"); // ??printf??

    // 创建 LED 控制任务
    // xTaskCreate(vTaskLEDControl, "LED Task", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);

   // 创建 LED 控制任务
    if (xTaskCreate(vTaskPrintfTestControl, "PRINTF Task", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 2, NULL) != pdPASS)
    {
        printf("Task creation failed!\n");
    }

    xTaskCreate(vTaskLEDControl, "LED Task", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 2, NULL);

    printf("开始启用调度起\n");
    // 启动调度器
    vTaskStartScheduler();

    printf("启用调度后\n");//不会有输出

    // 如果一切正常，程序永远不会到达这里
    for(;;);
}

















