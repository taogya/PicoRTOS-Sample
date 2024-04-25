
#include "blink.hpp"
#include "pico/stdlib.h"

Blink::Blink(int pin)
{
    this->pin = pin;
    gpio_init(pin);
    gpio_set_dir(pin, GPIO_OUT);
}

void Blink::toggle()
{
    gpio_put(pin, !gpio_get(pin));
}