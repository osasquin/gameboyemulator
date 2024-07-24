#include <stdio.h>
#include <cstdint>
#include "memory.h"
#include "CPU.h"
#include "interrupts.h"

void initialize(void){

    memory.romBank0 = 0;
    memory.romBank1 = 0;
    memory.vram = 0;
    memory.externalRam = 0;
    memory.workRam = 0;
    memory.oam = 0;
    memory.ioPorts = 0; //TODO
    memory.hram = 0;
    memory.interruptEnable = 0;
    memory.restartAddresses = 0;
    memory.headerData = 0;

    //acumulador
    registradores.A = 0x01;
    //flags
    registradores.F = 0xB0; // Z=1, N=1, H=1, C=0 (0xB0 = 10110000)
    //proposito geral
    registradores.B = 0xFF;
    registradores.C = 0x13;
    registradores.D = 0x00;
    registradores.E = 0xC1;
    registradores.H = 0x84;
    registradores.L = 0x03;
    //program counter
    registradores.PC = 0x0100;
    //stack pointer
    registradores.SP = 0xFFFE;

    interrupt.master = 0;
    interrupt.enable = 0;
    interrupt.flag = 0;

}

