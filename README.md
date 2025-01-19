# Projeto: Sistema com Teclado Matricial, LEDs e Buzzer usando Raspberry Pi Pico W

Este projeto implementa um sistema que utiliza um teclado matricial, LEDs RGB e um buzzer, desenvolvido para ser executado na placa Raspberry Pi Pico W. Ele permite capturar entradas do teclado, acionar LEDs coloridos e emitir sons com o buzzer. O código foi estruturado para funcionar tanto em simulação quanto em um ambiente físico, utilizando um teclado matricial real.

---

## Estrutura do Projeto

O código está dividido em quatro arquivos principais:

1. **`gpio-kp-buzzer-rgb.c`**  
   Arquivo principal que inicializa os componentes e define o loop principal do programa.
   
2. **`gpio.c` e `gpio.h`**  
   Contêm a configuração e controle dos LEDs RGB.

3. **`keypad.c` e `keypad.h`**  
   Implementam a inicialização e captura de entradas do teclado matricial.

4. **`buzzer.c` e `buzzer.h`**  
   Gerenciam o controle do buzzer, incluindo a configuração de PWM e a emissão de sons.

---

## Alterações no Código

O código foi modificado para suportar um teclado matricial físico conectado à placa Raspberry Pi Pico W. Especificamente, os pinos das linhas e colunas foram ajustados para os seguintes valores: 

```c
// Pinos das linhas e colunas
const uint gpio_rows[ROWS] = {18, 19, 20, 4};
const uint gpio_cols[COLS] = {9, 8, 16, 17};
```

Isso garante compatibilidade com o teclado real, permitindo a detecção precisa das teclas pressionadas. O teclado foi conectado à **porta de expansão P1** da Raspberry Pi Pico W, utilizando o kit de expansão da **BitDogLab**, que simplifica a conexão e o uso de componentes externos.

---

## Componentes Utilizados

- **Raspberry Pi Pico W**
- **Teclado Matricial 4x4**
- **Kit de Expansão BitDogLab (porta P1)**
- **LEDs RGB (vermelho, azul e verde)**
- **Buzzer**

---

## Como Executar o Programa

### 1. Configuração do Hardware (Parte Física)
- Faça esse passo caso queira fazer o teste na placa fisica.

1. **Conexões do Teclado Matricial**  
   Conecte o teclado matricial à **porta de expansão P1** utilizando o kit da **BitDogLab**.

   | Linha/Coluna | GPIO |
   |--------------|------|
   | Linha 1      | 18   |
   | Linha 2      | 19   |
   | Linha 3      | 20   |
   | Linha 4      | 4    |
   | Coluna 1     | 9    |
   | Coluna 2     | 8    |
   | Coluna 3     | 16   |
   | Coluna 4     | 17   |

2. **Conexões dos LEDs**  
   - LED Vermelho: GPIO 13
   - LED Verde: GPIO 11
   - LED Azul: GPIO 12

3. **Conexão do Buzzer**  
   Buzzer ao GPIO 21.

### 2. Configuração do Ambiente de Desenvolvimento

1. Instale o SDK do Raspberry Pi Pico W em sua máquina caso não tenha. Consulte o [guia oficial](https://github.com/raspberrypi/pico-sdk) para mais detalhes.
2. Clone ou copie o projeto para um diretório local.
3. Abra o diretório do projeto no VS Code.
4. Após a compilação, um arquivo `.uf2` será gerado.
5. Abra o arquivo diagram.json (responsavel por abrir a interface do simulador Wokwi) 

**Etapa para teste em componente fisico:** Conecte a Raspberry Pi Pico W ao computador em modo de armazenamento (pressione o botão BOOTSEL ao conectar o cabo USB). Copie o arquivo `.uf2` gerado para a unidade que aparecer.

  1. Após o upload do arquivo `.uf2`, a placa será reiniciada automaticamente.
  2. Abra um monitor serial (como o `minicom` ou o IDE de sua preferência) para visualizar os logs do programa.

---

## Instruções de Uso do Programa

- **Controle dos LEDs:**  
  - Tecla `A`: Acende o LED verde.  
  - Tecla `B`: Acende o LED azul.  
  - Tecla `C`: Acende o LED vermelho.  
  - Tecla `D`: Acende todos os LEDs.

- **Ativação do Buzzer:**  
  - Pressione a tecla `#` para emitir um som curto.

- **Logs para Depuração:**  
  - O monitor serial exibirá a tecla pressionada, útil para fins de depuração e testes.

---

## Considerações Finais

Equipe subgrupo 5
**Hércules Sampaio** - *Líder gerente de projeto*
**Keven Christian** - *Teclado matricial*   
**Giselle Oliveira** - *Teclado matricial*
**Marlon Santos** - *GPIO LEDs*   
**Jadson Sobrinho** - *Buzzer*   
**Wilton Lacerda** - *Video apresentação*

## Link Video
https://www.youtube.com/watch?v=wHV8VkldF6s
