
#include <FreeRTOS.h>
#include <task.h>

#include <cstdio>
#include <chrono>
#include <ctime>
#include "pico/stdlib.h"
#include "blink.hpp"

#define DEF_LED PICO_DEFAULT_LED_PIN
#define CASE_LED 22
#define DEF_LED_INTERVAL 1000
#define CASE_LED_INTERVAL 10

Blink def_led(DEF_LED);
Blink case_led(CASE_LED);
repeating_timer_t timer_def_led;
repeating_timer_t timer_case_led;

void print_current_time(const char *message)
{
    auto now = std::chrono::system_clock::now();
    auto now_time_t = std::chrono::system_clock::to_time_t(now);
    auto now_tm = *std::localtime(&now_time_t);

    char time_str[30];
    std::strftime(time_str, sizeof(time_str), "%H:%M:%S", &now_tm);

    auto now_ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;
    std::snprintf(time_str + 19, sizeof(time_str) - 19, ".%03lld", now_ms.count());

    printf("%s\t%s\n", time_str, message);
}

void task_def_led(void *parameters)
{
    while (true)
    {
        def_led.toggle();
        print_current_time("def_led Toggled");
        vTaskDelay(DEF_LED_INTERVAL);
    }
}
void task_case_led(void *parameters)
{
    while (true)
    {
        case_led.toggle();
        print_current_time("case_led Toggled");
        vTaskDelay(CASE_LED_INTERVAL);
    }
}

int main()
{
    TaskHandle_t def_ledTaskHandle = NULL;
    TaskHandle_t case_ledTaskHandle = NULL;

    stdio_init_all();
    xTaskCreate(task_def_led,
                "def_led",
                configMINIMAL_STACK_SIZE,
                NULL,
                configMAX_PRIORITIES - 1U,
                &def_ledTaskHandle);
    xTaskCreate(task_case_led,
                "case_led",
                configMINIMAL_STACK_SIZE,
                NULL,
                configMAX_PRIORITIES - 1U,
                &case_ledTaskHandle);

    /* Start the scheduler. */
    vTaskStartScheduler();
    while (true)
    {
        print_current_time("Wait");
        sleep_ms(1000);
    };

    return 0;
}

#if (configCHECK_FOR_STACK_OVERFLOW > 0)

void vApplicationStackOverflowHook(TaskHandle_t xTask,
                                   char *pcTaskName)
{
    /* Check pcTaskName for the name of the offending task,
     * or pxCurrentTCB if pcTaskName has itself been corrupted. */
    (void)xTask;
    (void)pcTaskName;
}

#endif /* #if ( configCHECK_FOR_STACK_OVERFLOW > 0 ) */

#if (configUSE_MALLOC_FAILED_HOOK > 0)

void vApplicationMallocFailedHook(void)
{
    /* vApplicationMallocFailedHook() will only be called if
     * configUSE_MALLOC_FAILED_HOOK is set to 1 in FreeRTOSConfig.h.
     * It is a hook function that will get called if a call to
     * pvPortMalloc() fails.
     */
    for (;;)
        ;
}

#endif /* #if ( configUSE_MALLOC_FAILED_HOOK > 0 ) */

#if (configUSE_TICK_HOOK > 0)

void vApplicationTickHook(void)
{
    /* vApplicationTickHook() will only be called if
     * configUSE_TICK_HOOK is set to 1 in FreeRTOSConfig.h.
     * It will get called for every tick increment.
     */
}

#endif /* #if ( configUSE_TICK_HOOK > 0 ) */