#define VBLANK_INTERRUPT (1 << 0)
#define LCD_INTERRUPT (1 << 1)
#define TIMER_INTERRUPT (1 << 2)
#define SERIAL_INTERRUPT (1 << 3)
#define JOYPAD_INTERRUPT (1 << 4)

typedef struct interrupt{
    uint8_t master; 
    uint8_t enable;
    uint8_t flag;
} extern interrupt;

void interruptStep(void);

void vBlank(void);
void LCD(void);
void timer(void);
void serial(void);
void joypad(void);

void interruptReturn(void);