// systick.c
#include "systick.h"
#include "stm32f4xx.h"

static volatile uint32_t tick_count = 0;

void systick_init(void) {
    SysTick->LOAD = 167999UL;   // (168MHz / 1000) - 1
    SysTick->VAL  = 0UL;        // clear current value
    SysTick->CTRL = (1 << 2)    // CLKSOURCE: processor clock
                  | (1 << 1)    // TICKINT:   enable interrupt
                  | (1 << 0);   // ENABLE:    start counter
}

// ISR — must match name in startup_stm32f4xx.s exactly
void SysTick_Handler(void) {
    tick_count++;
}

uint32_t get_tick(void) {
    return tick_count;
}

void delay_ms(uint32_t ms) {
    uint32_t start = tick_count;
    while ((tick_count - start) < ms) {
        __asm volatile("nop");
    }
}