#include <stdio.h>
#include "memory.h"
#include <cstdint>

typedef struct {
    uint8_t romBank0[ROM_BANK_0_SIZE];
    uint8_t romBank1[ROM_BANK_1_SIZE];
    uint8_t vram[VRAM_SIZE];
    uint8_t externalRam[EXTERNAL_RAM_SIZE];
    uint8_t workRam[WORK_RAM_SIZE];
    uint8_t oam[OAM_SIZE];
    uint8_t ioPorts[IO_PORTS_SIZE];
    uint8_t hram[HRAM_SIZE];
    uint8_t interruptEnable[INTERRUPT_ENABLE_SIZE];
    uint8_t restartAddresses[RESTART_ADDRESSES_SIZE];
    uint8_t headerData[HEADER_DATA_SIZE];
} Memory;


Memory memory;

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

void writeByte(uint16_t address, uint8_t value) {
    if (address < 0x4000)
        memory.romBank0[address] = value;
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
