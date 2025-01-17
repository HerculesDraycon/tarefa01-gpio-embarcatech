#include "pico/stdlib.h"
#include <stdio.h>

#define ROWS 4
#define COLS 4

// Configuração do teclado matricial
const uint row_pins[ROWS] = {26, 22, 21, 20}; // Pinos das linhas
const uint col_pins[COLS] = {19, 18, 17, 16}; // Pinos das colunas
const char keys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

void keypad_init() {
    for (int i = 0; i < ROWS; i++) {
        gpio_init(row_pins[i]);
        gpio_set_dir(row_pins[i], GPIO_OUT);
        gpio_put(row_pins[i], 1); // Linha desativada
    }
    for (int j = 0; j < COLS; j++) {
        gpio_init(col_pins[j]);
        gpio_set_dir(col_pins[j], GPIO_IN);
        gpio_pull_up(col_pins[j]);
    }
}

char keypad_scan() {
    for (int i = 0; i < ROWS; i++) {
        gpio_put(row_pins[i], 0); // Ativa a linha
        for (int j = 0; j < COLS; j++) {
            if (gpio_get(col_pins[j]) == 0) {
                sleep_ms(50); // Debouncing
                if (gpio_get(col_pins[j]) == 0) {
                    gpio_put(row_pins[i], 1); // Desativa a linha
                    return keys[i][j];
                }
            }
        }
        gpio_put(row_pins[i], 1); // Desativa a linha
    }
    return '\0'; // Nenhuma tecla pressionada
}

int main() {
    stdio_init_all();
    keypad_init();

    printf("Iniciando...\n");

    while (true) {
        char key = keypad_scan();
        if (key != '\0') {
            printf("Tecla pressionada: %c\n", key);
        }
        sleep_ms(100);
    }

    return 0;
}