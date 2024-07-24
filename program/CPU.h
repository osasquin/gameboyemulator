#include <stdio.h>
#include <cstdint>

/*
-----------------------------------------------------------------------------
                                REGISTRADORES
-----------------------------------------------------------------------------
*/

typedef struct{
    uint8_t A; //Acumulador geral
    uint8_t F; //flags (Z, N, H, C)
    uint8_t B, C, D, E, H, L; //propósito geral (General Porpouse)
    uint16_t SP; //Stack-Pointer
    uint8_t PC; //Program-Counter
} REGISTRADORES;

REGISTRADORES registradores;

/*
-----------------------------------------------------------------------------
                                 FLAGS
-----------------------------------------------------------------------------
*/

// Reference by: Cinoop

#define FLAGS_ZERO (1 << 7)
#define FLAGS_NEGATIVE (1 << 6)
#define FLAGS_HALFCARRY (1 << 5)
#define FLAGS_CARRY (1 << 4)

#define FLAGS_ISZERO (registers.f & FLAGS_ZERO)
#define FLAGS_ISNEGATIVE (registers.f & FLAGS_NEGATIVE)
#define FLAGS_ISCARRY (registers.f & FLAGS_CARRY)
#define FLAGS_ISHALFCARRY (registers.f & FLAGS_HALFCARRY)

#define FLAGS_ISSET(x) (registers.f & (x))
#define FLAGS_SET(x) (registers.f |= (x))
#define FLAGS_CLEAR(x) (registers.f &= ~(x))

/*
-----------------------------------------------------------------------------
                                INSTRUCTIONS
-----------------------------------------------------------------------------
*/

struct instruction {
	char *disassembly;
	unsigned char operandLength;
	void *execute;
	//unsigned char ticks;
} extern const instructions[256];

extern const unsigned char instructionTicks[256];

extern unsigned long ticks;
extern unsigned char stopped;