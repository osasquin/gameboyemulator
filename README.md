# Emulador de Game Boy: Um Estudo em Programação Embarcada de Baixo Nível

## Visão Geral

Este projeto é uma implementação de um emulador para o Game Boy clássico, desenvolvido inteiramente em C. Mais do que um simples software, este emulador representa um estudo aprofundado sobre a arquitetura de hardware de sistemas embarcados e a programação de baixo nível. O objetivo central é recriar, via software, o comportamento do hardware original do Game Boy, demonstrando um entendimento prático de conceitos como arquitetura de CPU, gerenciamento de memória, ciclos de máquina e tratamento de interrupções.

Este projeto é uma vitrine de habilidades essenciais para a área de sistemas embarcados, onde a interação direta com o hardware e a otimização de recursos são fundamentais.

## Análise de Hardware e Arquitetura

O núcleo do emulador reside na sua capacidade de simular fielmente os componentes de hardware do Game Boy. A análise e implementação desses componentes são a base deste projeto.

### CPU (Processador Sharp LR35902)

O coração do Game Boy é um processador 8-bit customizado pela Sharp, um híbrido entre o Z80 e o Intel 8080. A emulação deste componente é realizada nos arquivos `program/CPU.c` e `program/CPU.h`.

  * **Emulação do Conjunto de Instruções (ISA):** O arquivo `program/CPU.c` implementa o decodificador de *opcodes*. Cada instrução em assembly do processador é mapeada para uma função ou bloco de código em C que replica seu comportamento. Isso inclui operações aritméticas, lógicas, manipulação de bits e controle de fluxo.
  * **Registradores:** A estrutura da CPU, incluindo seus registradores de 8 e 16 bits (A, F, B, C, D, E, H, L, SP, PC), é modelada em software para manter o estado do processador a cada ciclo de clock.
  * **Ciclos de Máquina:** O `main.c` contém o loop principal que orquestra a execução da CPU, buscando, decodificando e executando uma instrução por vez, simulando o ciclo de fetch-decode-execute de um processador real.

### Gerenciamento de Memória (MMU)

Sistemas embarcados raramente possuem um sistema de memória unificado. O Game Boy utiliza um mapa de memória segmentado, que é crucial para o funcionamento dos jogos e do próprio hardware. O arquivo `program/memory.c` é responsável por emular essa arquitetura.

  * **Memory Mapped I/O (MMIO):** O emulador simula o acesso a diferentes regiões de memória, como a ROM do cartucho, a VRAM (Video RAM), a WRAM (Work RAM) e, crucialmente, os registradores de I/O, que controlam periféricos como a PPU (Picture Processing Unit) e o APU (Audio Processing Unit). A escrita e leitura em endereços específicos de memória disparam ações de "hardware" simulado, um conceito fundamental em programação embarcada.
  * **Controle de Bancos de Memória (MBC):** A lógica para a troca de bancos de ROM e RAM, presente nos cartuchos de Game Boy, é um exemplo clássico de como sistemas com recursos limitados expandem sua capacidade de endereçamento.

### Sistema de Interrupções

O tratamento de interrupções é vital para a operação assíncrona e em tempo real de qualquer sistema embarcado. Os arquivos `program/interrupts.c` e `program/interrupts.h` implementam o controlador de interrupções do Game Boy.

  * **Fontes de Interrupção:** O código gerencia as cinco fontes de interrupção do sistema: V-Blank (sinaliza que a tela pode ser redesenhada), LCD STAT, Timer, Serial e Joypad.
  * **Vetor de Interrupções:** A lógica de desvio do fluxo de execução para as rotinas de tratamento de interrupção (ISRs), a verificação dos registradores de habilitação (IE) e de flags (IF) são simuladas para garantir que o software do jogo responda corretamente aos eventos de hardware.

## Programação Assembly em C

Este projeto pode ser visto como uma tradução funcional do conjunto de instruções assembly do processador Sharp LR35902 para a linguagem C. Cada *opcode* lido da ROM do jogo é essencialmente uma instrução em linguagem de máquina que é interpretada e executada.

**Exemplo de Tradução Assembly -\> C:**

Considere a instrução assembly `LD A, (HL)`. Esta instrução carrega o valor contido no endereço de memória apontado pelo registrador de 16 bits `HL` para o registrador de 8 bits `A`. Em `program/CPU.c`, sua implementação seria equivalente a:

```c
// Exemplo hipotético baseado na estrutura do projeto
case 0x7E: // Opcode para LD A, (HL)
    cpu->registers.a = memory_read(cpu->registers.hl);
    cycles_executed = 8;
    break;
```

Esta abordagem demonstra uma compreensão profunda de como as abstrações de alto nível se relacionam com as operações de baixo nível da máquina.

## Como Compilar e Executar

Este projeto utiliza um `MakeFile` para a compilação e depende da biblioteca SDL2 para a criação da janela, renderização dos gráficos e captura de input do teclado.

### Dependências

  * GCC (ou outro compilador C)
  * Make
  * Biblioteca SDL2

### Passos para Compilação

1.  **Clone o repositório:**
    ```bash
    git clone <URL_DO_REPOSITORIO>
    cd <NOME_DO_DIRETORIO>
    ```
2.  **Compile o projeto:**
    Execute o comando `make` no terminal. O `MakeFile` se encarregará de compilar os arquivos-fonte e linkar com a biblioteca SDL2.
    ```bash
    make
    ```
3.  **Execute:**
    Após a compilação, um executável será gerado. Execute-o a partir da linha de comando, passando o caminho para uma ROM de Game Boy como argumento.
    ```bash
    ./main.exe caminho/para/sua/rom.gb
    ```

## References
* https://cturt.github.io/cinoop.html
* http://gameboy.mongenel.com/dmg/opcodes.html
* https://github.com/CTurt/Cinoop
* https://github.com/deltabeard/gameboy-c
* https://chatgpt.com/share/5b22b36f-cdba-459f-b7ea-bf17d40ad835
* https://www.codemotion.com/magazine/frontend/gamedev/how-to-build-an-emulator/
* https://gustavoarraes.notion.site/Game-Boy-Emulator-ea5d86eafb3b4070a0d1a5a723d5de95?pvs=4
* https://gbdev.io/pandocs/
