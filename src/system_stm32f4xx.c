#include "system_stm32f4xx.h"
#include <stdint.h>

void SystemInit(void) {
    // intentionally empty
    // bare-metal clock is already running on HSI (16MHz default)
    // we configure nothing here — main.c handles everything
}

void SystemCoreClockUpdate(void) {
    // intentionally empty
}