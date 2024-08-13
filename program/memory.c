#include <stdio.h>
#include "memory.h"
#include <cstdint>


uint8_t readByte(uint16_t address) {
    if (address < 0x4000)
        return memory.romBank0[address];
    else if (address < 0x8000)
        return memory.romBank1[address - 0x4000];
    else if (address < 0xA000)
        return memory.vram[address - 0x8000];
    else if (address < 0xC000)
        return memory.externalRam[address - 0xA000];
    else if (address < 0xE000)
        return memory.workRam[address - 0xC000];
    else if (address < 0xFE00)
        return memory.workRam[address - 0xE000];  // Echo RAM
    else if (address < 0xFEA0)
        return memory.oam[address - 0xFE00];
    else if (address < 0xFF00)
        return 0;  //Memória não usada
    else if (address < 0xFF80)
        return memory.ioPorts[address - 0xFF00];
    else if (address < 0xFFFF)
        return memory.hram[address - 0xFF80];
    else
        return memory.interruptEnable[0];
}

uint16_t readTwoBytes(uint16_t address){
    uint16_t data = readByte(address) | readByte(address + 1 << 8);
    return data;
}

void writeByte(uint16_t address, uint8_t value) {
    if (address < 0x4000){
        memory.romBank0[address] = value;}
    else if (address < 0x8000)
        memory.romBank1[address - 0x4000] = value;
    else if (address < 0xA000)
        memory.vram[address - 0x8000] = value;
    else if (address < 0xC000)
        memory.externalRam[address - 0xA000] = value;
    else if (address < 0xE000)
        memory.workRam[address - 0xC000] = value;
    else if (address < 0xFE00)
        memory.workRam[address - 0xE000] = value;  // Echo RAM
    else if (address < 0xFEA0)
        memory.oam[address - 0xFE00] = value;
    else if (address < 0xFF00)
        ;  //Memória não usada
    else if (address < 0xFF80)
        memory.ioPorts[address - 0xFF00] = value;
    else if (address < 0xFFFF)
        memory.hram[address - 0xFF80] = value;
    else
        memory.interruptEnable[0] = value;
}

void writeTwoBytes(uint16_t address, uint16_t value) {
    writeByte(address, (uint8_t)(value & 0x00FF));
    writeByte(address + 1, (uint8_t)((value & 0xFF00) >> 8));
}

void writeTwoBytesToStack(uint16_t value){
    registers.sp -= 2;
    writeTwoBytes(register.sp, value);
}