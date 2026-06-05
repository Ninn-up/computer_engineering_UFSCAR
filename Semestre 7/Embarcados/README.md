# Trabalhos de Projeto de Sistemas Computacionais Embarcados

Este repositório contém os projetos desenvolvidos para a disciplina de Projeto de Sistemas Computacionais Embarcados na Universidade Federal de São Carlos, sob orientação do Prof. Emerson Pedrino.

## Autores
* Nicole Correa Ramos (823127)
* Nicolas Queiroz Bertozzo (822070) 

---

## Estrutura do Projeto

O repositório está organizado em quatro práticas principais, abrangendo desde o controle de periféricos básicos de entrada e saída até a implementação complexa de jogos em displays gráficos.

### Prática 1: Gravador para o Microcontrolador 89S52 com Arduino
Esta prática inicial teve como foco a familiarização com o fluxo de compilação, simulação e gravação física do microcontrolador 89S52.
* **Funcionamento:** Implementação de um programa simples para acender e desligar um LED continuamente (Blinking LED).
* **Ferramentas:** Uso do simulador EdSim51, interface com Arduino Nano (atuando como fonte de +5V/GND e ISP) e o software gravador para o microcontrolador.
* **Objetivo:** Compreender a estrutura de um código na linguagem Assembly, o uso de sub-rotinas de atraso e o carregamento do arquivo `.hex` na placa.

### Prática 2: Teclado Numérico e Display LCD
Integração de periféricos externos ao microcontrolador utilizando suas portas de E/S.
* **Funcionamento:** Leitura de um teclado numérico matricial 4x3 e exibição simultânea das teclas pressionadas em um display LCD operando em modo de comunicação de 4 bits.
* **Tratamento de Sinal:** Aplicação da rotina `ESPSOL` via temporizador para eliminar o efeito mecânico de *bouncing* nos botões.
* **Objetivo:** Dominar a técnica de varredura de linhas e colunas para identificação de botões e o envio de comandos de inicialização e caracteres para o controlador do LCD.

### Prática 3: Senha de Cofre LCD
Desenvolvimento de uma lógica de controle de acesso semelhante a um cofre eletrônico.
* **Funcionamento:** O sistema lê a entrada do teclado, substitui visualmente os dígitos por asteriscos (*) no display para ocultar a senha, e compara a entrada final com um código predefinido, liberando ou bloqueando o acesso.
* **Comparativo de Linguagens:** O projeto foi desenvolvido primeiramente em Assembly e depois portado integralmente para a linguagem C.
* **Objetivo:** Observar as vantagens de estruturação, isolamento de funções e manipulação de *arrays* fornecidas pela linguagem de alto nível, consolidando a lógica do hardware abordada anteriormente.

### Prática 4: Jogos em LCD e GLCD
Exploração avançada de renderização gráfica implementando minijogos interativos.
* **Jogo T-Rex:** Implementado em duas versões (LCD e GLCD). A versão para LCD explora a memória CGRAM para gerar caracteres customizados (Dino, Cacto e Nuvem). A versão para GLCD mapeia *sprites* 8x8 diretamente da ROM para a GDRAM, exigindo controle de pixels.
* **Jogo Stock Car:** Desenvolvido exclusivamente para o GLCD, onde o jogador deve desviar de outros veículos em uma estrada.
* **Técnicas Aplicadas:** O jogo de corrida introduz rolagem de cenário otimizada utilizando *buffer circular* para mitigar limitações de RAM, e um "modo noturno" para simular o alcance de faróis.

---

## Requisitos e Ferramentas
* **Simuladores e Software:** EdSim51, IDE do Arduino, Gravador de Firmware (DC/UFSCar).
* **Hardware:** Microcontrolador AT89S52 (família 8051), Arduino Nano, Teclado Matricial 4x3, Display LCD 16x2 e Display GLCD (controlador ST7920).
* **Linguagens:** Assembly e C.