#ifndef GPIO_H
#define GPIO_H

#include "pico/stdlib.h"

// Definição dos pinos dos leds
#define LED_RED 13
#define LED_GREEN 11
#define LED_BLUE 12

void led_init();
void led_on(char _key);

#endif