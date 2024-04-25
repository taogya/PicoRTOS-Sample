
#include <stdlib.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/uart.h>
#include <string.h>
#include <zephyr/usb/usb_device.h>
#include <zephyr/drivers/uart.h>

#define DEF_LED_NODE DT_ALIAS(def_led)
#define CASE_LED_NODE DT_ALIAS(case_led)

#define SLEEP_TIME_MS_DEF_LED K_MSEC(1000 - 1)
#define SLEEP_TIME_MS_CASE_LED K_MSEC(10 - 1)

bool usb_ready = false;

void print_current_time(const char *message)
{
    int64_t now = k_uptime_get();

    int64_t hours = now / 1000 / 60 / 60;
    int64_t minutes = (now / 1000 / 60) % 60;
    int64_t seconds = (now / 1000) % 60;

    printk("%02lld:%02lld:%02lld\t%s\n", hours, minutes, seconds, message);
    // printk("%s\n", message);
}

void def_led_thread(void *p1, void *p2, void *p3) {
    const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(DEF_LED_NODE, gpios);

    gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);

    while (1) {
        gpio_pin_toggle_dt(&led);
		if(usb_ready){
        	print_current_time("def_led Toggled");
		}
        k_sleep(SLEEP_TIME_MS_DEF_LED);
    }
}

void case_led_thread(void *p1, void *p2, void *p3) {
    const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(CASE_LED_NODE, gpios);

    gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);

    while (1) {
        gpio_pin_toggle_dt(&led);
		if(usb_ready){
        	print_current_time("case_led Toggled");
		}
        k_sleep(SLEEP_TIME_MS_CASE_LED);
    }
}

void usb_thread(void *p1, void *p2, void *p3)
{
	const struct device *usb_device = DEVICE_DT_GET(DT_CHOSEN(zephyr_console));
	uint32_t dtr = 0;

    /* Check if USB can be initialised, bails out if fail is returned */
	if (usb_enable(NULL) != 0) {
		return;
	}

	/* Wait for a console connection, if the DTR flag was set to activate USB.
     * If you wish to start generating serial data immediately, you can simply
     * remove the while loop, to not wait until the control line is set.    
     */
	while (!dtr) {
		uart_line_ctrl_get(usb_device, UART_LINE_CTRL_DTR, &dtr);
		k_sleep(K_MSEC(100));
	}

	printk("USB ready\n");
	usb_ready = true;
}


K_THREAD_DEFINE(def_led_id, 500, def_led_thread, NULL, NULL, NULL, 5, 0, 0);
K_THREAD_DEFINE(case_led_id, 500, case_led_thread, NULL, NULL, NULL, 5, 0, 0);
K_THREAD_DEFINE(usb_id, 500, usb_thread, NULL, NULL, NULL, 5, 0, 0);
