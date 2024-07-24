/*
- **0000-3FFF:** ROM banco 0.
- **4000-7FFF:** ROM banco 1.
- **8000-9FFF:** Video RAM (VRAM).
- **A000-BFFF:** External RAM (cartucho).
- **C000-DFFF:** Working RAM (WRAM).
- **E000-FDFF:** Echo de WRAM.
- **FE00-FE9F:** OAM (Sprite Attribute Table).
- **FF00-FF7F:** I/O Ports.
- **FF80-FFFE:** High RAM (HRAM).
- **FFFF:** Interrupt Enable Register.
*/

//Endereços reservados
#define RESTART_ADDRESSES_SIZE 0x40
#define HEADER_DATA_SIZE 0x50

//Tamanhos de Memória
#define ROM_BANK_0_SIZE 0x4000
#define ROM_BANK_1_SIZE 0x4000
#define VRAM_SIZE 0x2000
#define EXTERNAL_RAM_SIZE 0x2000
#define WORK_RAM_SIZE 0x2000
#define OAM_SIZE 0xA0
#define IO_PORTS_SIZE 0x80
#define HRAM_SIZE 0x7F
#define INTERRUPT_ENABLE_SIZE 0x1

//Endereços de Memória
#define ROM_BANK_0_START 0x0000
#define ROM_BANK_1_START 0x4000
#define VRAM_START 0x8000
#define EXTERNAL_RAM_START 0xA000
#define WORK_RAM_START 0xC000
#define ECHO_RAM_START 0xE000
#define OAM_START 0xFE00
#define IO_PORTS_START 0xFF00
#define HRAM_START 0xFF80
#define INTERRUPT_ENABLE_START 0xFFFF

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

void readByte(void);
void readTwoBytes(void);
void writeByte(void);
void writeTwoBytes(void);