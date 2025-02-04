//Tarefa U4C5 feita por Maria Eduarda Santos Campos.

#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"

//LEDs e botões
#define LED_VM 13 //LED Vermelho
#define LED_AZ 12 //LED Azul
#define LED_VD 11 //LED Verde
#define BOTAO 5   //Pushbutton

//Variável de controle para evitar que o botão seja acionado antes do último LED se desligar
volatile bool botao_pressionado = true; 

//Protótipo das funções de callback
int64_t turn_off_callback2(alarm_id_t id, void *user_data);
int64_t turn_off_callback3(alarm_id_t id, void *user_data);

//Função de callback 1 - Desliga o primeiro LED
int64_t turn_off_callback1(alarm_id_t id, void *user_data) { 
    gpio_put(LED_AZ, 0);
    add_alarm_in_ms(3000, turn_off_callback2, NULL, false); //Chama a função 2
    
    return false;
}

//Função de callback 1 - Desliga o segundo LED
int64_t turn_off_callback2(alarm_id_t id, void *user_data) { 
    gpio_put(LED_VM, 0);
    add_alarm_in_ms(3000, turn_off_callback3, NULL, false); //Chama a função 3
    
    return false;
}

//Função de callback 1 - Desliga o terceiro LED
int64_t turn_off_callback3(alarm_id_t id, void *user_data) { 
    gpio_put(LED_VD, 0);
    botao_pressionado = true; //Permite acionar novamente o botão
    return false;
}

//Função principal
int main() {
    stdio_init_all();

    //Inicializações
    gpio_init(LED_VM);
    gpio_init(LED_AZ);
    gpio_init(LED_VD);
    gpio_init(BOTAO);

    //Definições de entrada e saída
    gpio_set_dir(LED_VM, true);
    gpio_set_dir(LED_AZ, true);
    gpio_set_dir(LED_VD, true);
    gpio_set_dir(BOTAO, false);

    //Define botão em nível alto
    gpio_pull_up(BOTAO);

    //Loop infinito
    while (true) {
        if(gpio_get(BOTAO) == 0){
            //Atraso de Debounce para evitar erros
            sleep_ms(50);   
            if(botao_pressionado && gpio_get(BOTAO) == 0){
                //Liga todos os LEDs
                gpio_put(LED_VM, 1);
                gpio_put(LED_AZ, 1);
                gpio_put(LED_VD, 1);
                botao_pressionado = false; //Não permite que o botão seja acionado de novo até que essa váriavel se torne verdadeira (true)
                //Agenda um alarme para executar a função turn_off_callback1 após 3 segundos (3000 ms)
                add_alarm_in_ms(3000, turn_off_callback1, NULL, false);
            }
        }
        sleep_ms(10);
    }
}
