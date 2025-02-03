//Tarefa U4C5 feita por Maria Eduarda Santos Campos.

#include <stdio.h> 
#include "pico/stdlib.h"     
#include "hardware/clocks.h" 
#include "hardware/pll.h"    

//LEDs vermelho, amarelop e verde
#define LED_VM 13 //Na placa BitDogLab, led verde
#define LED_AM 12 //Na placa BitDogLab, led azul
#define LED_VD 11 //Na placa BitDogLab, led vermelho

// Função de callback
bool repeating_timer_callback(struct repeating_timer *t) {
    //Liga a amarela e desliga o resto
    if(gpio_get(LED_VM) == 1&&gpio_get(LED_VD) == 0&&gpio_get(LED_AM) == 0){
        gpio_put(LED_VM, false);
        gpio_put(LED_AM, true); 
        gpio_put(LED_VD, false);
    }else //Liga a verde e desliga o resto
    if(gpio_get(LED_VM) == 0&&gpio_get(LED_VD) == 0&&gpio_get(LED_AM) == 1){
        gpio_put(LED_VM, false);
        gpio_put(LED_AM, false);        
        gpio_put(LED_VD, true);
    }else //Liga a vermelha e desliga o resto
    if(gpio_get(LED_VM) == 0&&gpio_get(LED_VD) == 1&&gpio_get(LED_AM) == 0){
        gpio_put(LED_VM, true); 
        gpio_put(LED_AM, false);
        gpio_put(LED_VD, false);
    }
    return true; //Retorna verdadeiro ou falso para continuar ou parar o temporizador.
}

//Função principal
int main() {
    stdio_init_all();

    //Inicializa e define os LEDs como saída
    gpio_init(LED_VM);
    gpio_init(LED_AM);
    gpio_init(LED_VD);
    gpio_set_dir(LED_VM, true);
    gpio_set_dir(LED_AM, true);
    gpio_set_dir(LED_VD, true);
    
    //Liga o LED vermelho inicialamente
    gpio_put(LED_VM, true);

    //Estrutura de temporizador de repetição que armazena informações sobre o temporizador configurado.
    struct repeating_timer timer;

    //Chama a função de callback a cada três segundos
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    while (true){
        //Mostra no terminal quantos segundos se passaram de 3 em 3 segundos
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