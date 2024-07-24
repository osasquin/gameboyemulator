#include "interrupts.h"
#include "memory.h"

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
    writeTwoBytes();
}