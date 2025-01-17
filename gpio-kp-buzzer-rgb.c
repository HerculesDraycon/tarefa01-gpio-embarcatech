#include "pico/stdlib.h"
#include "gpio.h"
#include "buzzer.h"
#include "keypad.h"
#include <stdio.h>

int main() {
    stdio_init_all(); // Inicializa comunicação serial
    init_gpio();      // Inicializa LEDs
    pwm_init_buzzer(BUZZER_PIN); // Inicializar o Buzzer
    init_keypad();    // Inicializa teclado matricial

    printf("Sistema iniciado. Pressione teclas no teclado matricial.\n");

    while (1) {
        char key = get_key(); // Captura a tecla pressionada

        // Controle dos LEDs
        gpio_put(LED_GREEN, (key == 'A' || key == 'D')); // A ou D -> LED verde
        gpio_put(LED_BLUE, (key == 'B' || key == 'D'));  // B ou D -> LED azul
        gpio_put(LED_RED, (key == 'C' || key == 'D'));   // C ou D -> LED vermelho

        // Controle do Buzzer
        if (key == '#') {

            beep(BUZZER_PIN, 500); // Liga o buzzer com duração de 5ms
 
        }
        // Log para depuração
        if (key) {
            printf("Tecla pressionada: %c\n", key);
        }

        sleep_ms(50); // Pequeno atraso para evitar leituras repetidas
    }

    return 0;
}
