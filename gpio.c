#include "gpio.h"

// Inicialização dos pinos dos leds
void led_init() {
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);

    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);

    gpio_init(LED_BLUE);
    gpio_set_dir(LED_BLUE, GPIO_OUT);
}

// Liga o led a partir do valor de retorno da tecla pressionada
void led_on(char _key) {
    gpio_put(LED_GREEN, (_key == 'A' || _key == 'D'));
    gpio_put(LED_BLUE, (_key == 'B' || _key == 'D'));
    gpio_put(LED_RED, (_key == 'C' || _key == 'D'));
}