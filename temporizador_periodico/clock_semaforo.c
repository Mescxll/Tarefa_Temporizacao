//Tarefa U4C5 feita por Maria Eduarda Santos Campos

#include <stdio.h> //Biblioteca padrão do C
#include "pico/stdlib.h"     // Biblioteca padrão para funções básicas de E/S, temporização, controle de GPIO, etc.
#include "hardware/clocks.h" // Biblioteca para configuração e gerenciamento dos clocks do microcontrolador RP2040.
#include "hardware/pll.h"    // Biblioteca para controle e configuração dos Phase-Locked Loops (PLLs).

#define LED_VM 11
#define LED_AM 12
#define LED_VD 13



// Função de callback que será chamada repetidamente pelo temporizador
// O tipo bool indica que a função deve retornar verdadeiro ou falso para continuar ou parar o temporizador.
bool repeating_timer_callback(struct repeating_timer *t) {
    if(gpio_get(LED_VM) == 1&&gpio_get(LED_VD) == 0&&gpio_get(LED_AM) == 0){
        gpio_put(LED_VM, false);
        gpio_put(LED_AM, true); 
        gpio_put(LED_VD, false);
    }else if(gpio_get(LED_VM) == 0&&gpio_get(LED_VD) == 0&&gpio_get(LED_AM) == 1){
        gpio_put(LED_VM, false);
        gpio_put(LED_AM, false);        
        gpio_put(LED_VD, true);
    }else if(gpio_get(LED_VM) == 0&&gpio_get(LED_VD) == 1&&gpio_get(LED_AM) == 0){
        gpio_put(LED_VM, true); 
        gpio_put(LED_AM, false);
        gpio_put(LED_VD, false);
    }
    return true;
}

int main() {//função principal
    // Inicializa a comunicação serial, permitindo o uso das funções padrão de E/S como printf.
    stdio_init_all();

    //Configura a frequência do clock do sistema (clk_sys) para um valor específico em kHz
    //set_sys_clock_khz(100000, false);

    gpio_init(LED_VM);
    gpio_init(LED_AM);
    gpio_init(LED_VD);
    gpio_set_dir(LED_VM, true);
    gpio_set_dir(LED_AM, true);
    gpio_set_dir(LED_VD, true);
    // Declaração de uma estrutura de temporizador de repetição.
    // Esta estrutura armazenará informações sobre o temporizador configurado.
    gpio_put(LED_VM, true);

    struct repeating_timer timer;

    // Configura o temporizador para chamar a função de callback a cada 1 segundo.
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    while (true){
        printf("Um segundo se passou\n");
        sleep_ms(1000);
        printf("Dois segundos se passaram\n");
        sleep_ms(1000);
        printf("Três segundos se passaram\n");
        sleep_ms(1000);
        printf(" \n");
    }

    return 0;
}