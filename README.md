# Tarefa U4C5 - Conceituando clock e temporizadores 
Atividades implementadas: temporizador periódico e temporizador de um disparo (one shot).

## Atividade 1: Temporizador Periódico

### Descrição
Nesta atividade, um semáforo com temporização de 3 segundos foi implementado utilizando a função `add_repeating_timer_ms()` do Pico SDK. O sistema alterna entre os sinais vermelho, amarelo e verde de forma sequencial, a cada 3 segundos.

### Componentes Necessários
- Microcontrolador Raspberry Pi Pico W
- 03 LEDs (vermelho, amarelo e verde)
- 03 Resistores de 330 Ω

### Execução
1. Clone este repositório:
   ```sh
   git clone https://github.com/Mescxll/Tarefa_Temporizacao.git
   ```
2. Compile e carregue o código no Raspberry Pi Pico W utilizando o VS Code e o Pico SDK.
3. Utilize o simulador Wokwi para testar o funcionamento do semáforo.
4. Verifique a saída da porta serial para confirmação das mensagens.

---

## Atividade 2: Temporizador de um Disparo (One Shot)

### Descrição
Nesta atividade foi implementado um sistema de temporização para acionar LEDs a partir do clique de um botão, utilizando a função `add_alarm_in_ms()` do Pico SDK. O sistema ao pressionar o botão desliga um LED por vez, respeitando a temporização (3 segundos).

### Componentes Necessários
- Microcontrolador Raspberry Pi Pico W
- 03 LEDs (azul, vermelho e verde)
- 03 Resistores de 330 Ω
- 01 Botão (Pushbutton)

### Execução
1. Clone este repositório:
   ```sh
   git clone https://github.com/Mescxll/Tarefa_Temporizacao.git
   ```
2. Compile e carregue o código no Raspberry Pi Pico W utilizando o VS Code e o Pico SDK.
3. Utilize o simulador Wokwi para testar o funcionamento do sistema.
4. Pressione o botão e verifique as mudanças de estado dos LEDs.




