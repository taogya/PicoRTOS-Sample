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

bool repeating_timer_callback_def_led(repeating_timer_t *rt)
{
    def_led.toggle();
    print_current_time("def_led Toggled");
    return true;
}
bool repeating_timer_callback_case_led(repeating_timer_t *rt)
{
    case_led.toggle();
    print_current_time("case_led Toggled");
    return true;
}

int main()
{
    stdio_init_all();

    // Timer example code - This example fires off the callback after 2000ms
    auto res_def_led = add_repeating_timer_ms(DEF_LED_INTERVAL, repeating_timer_callback_def_led, NULL, &timer_def_led);
    auto res_case_led = add_repeating_timer_ms(CASE_LED_INTERVAL, repeating_timer_callback_case_led, NULL, &timer_case_led);
    while (true)
    {

        print_current_time("Wait");
        sleep_ms(1000);
    };

    return 0;
}
