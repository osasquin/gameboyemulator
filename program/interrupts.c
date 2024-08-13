#include "interrupts.h"
#include "memory.h"
#include "CPU.h"

void interruptStep(void){
    if(interrupt.master && interrupt.enable && interrupt.flag){
        uint8_t interrupcao = interrupt.enable & interrupt.flag //se o bit for o mesmo nos dois, é a interrupcao que queremos

        if(interrupcao & VBLANK_INTERRUPT){
            interrupcao.flag &= ~VBLANK_INTERRUPT;
            vBlank();
        }
        if(interrupcao & LCD_INTERRUPT){
            interrupcao.flag &= ~LCD_INTERRUPT;
            LCD();
        }
         if(interrupcao & TIMER_INTERRUPT){
            interrupcao.flag &= ~TIMER_INTERRUPT;
            timer();
        }
        if(interrupcao & SERIAL_INTERRUPT){
            interrupcao.flag &= ~SERIAL_INTERRUPT;
            serial();
        }
        if(interrupcao & JOYPAD_INTERRUPT){
            interrupcao.flag &= ~JOYPAD_INTERRUPT;
            joypad();
        }                   
    }

}

void vBlank(void){
    //TODO SDL, LCD;
    interrupt.master = 0;
    writeTwoBytesToStack(registradores.PC);
    registers.pc = 0x48;
    /
}

void LCD(void){
    //TODO SDL, LCD;
    interrupt.master = 0;
    writeTwoBytesToStack(registers.pc);
    registers.pc = 0x50;
    //TODO ticks
}

void timer(void){
    //TODO SDL, LCD;
    interrupt.master = 0;
    writeTwoBytesToStack(registers.pc);
    registers.pc = 0x58;
    //TODO ticks
}

void serial(void){
    //TODO SDL, LCD;
    interrupt.master = 0;
    writeTwoBytesToStack(registers.pc);
    registers.pc = 0x60;
    //TODO ticks
}

void joypad(void){
    //TODO SDL, LCD;
    interrupt.master = 0;
    writeTwoBytesToStack(registers.pc);
    registers.pc = 0x68;
    //TODO ticks
}

// Master 1 habilita o handling do interrupt
// Retorna o endereço no qual o programa deverá ser desviado
void interruptReturn(void){
    interrupt.master = 1;
    register.pc = readTwoBytes(register.sp);
}
