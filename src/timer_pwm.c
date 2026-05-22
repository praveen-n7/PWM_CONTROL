#include "timer_pwm.h"
#include "stm32f4xx.h"

void pwm_init(void) {
    /* --- Clock enables --- */
    RCC->AHB1ENR |= (1 << 0);   // GPIOAEN
    RCC->APB1ENR |= (1 << 0);   // TIM2EN

    /* --- PA5: AF1 (TIM2_CH1), high speed --- */
    GPIOA->MODER   &= ~(3U << 10);
    GPIOA->MODER   |=  (2U << 10);   // Alternate Function
    GPIOA->OSPEEDR |=  (3U << 10);   // High speed
    GPIOA->AFR[0]  &= ~(0xFU << 20);
    GPIOA->AFR[0]  |=  (0x1U << 20); // AF1 = TIM2

    /* --- TIM2 PWM configuration --- */
    TIM2->PSC  = 83;      // 84MHz / 84 = 1 MHz (1 us/tick)
    TIM2->ARR  = 19999;   // 20000 us = 20 ms period = 50 Hz
    TIM2->CCR1 = 1500;    // default: 90 degrees

    // CCMR1: OC1M=0b110 (PWM Mode 1), OC1PE=1 (preload enable)
    TIM2->CCMR1 = (6U << 4) | (1U << 3);

    // CCER: CC1E=1 (channel 1 output enable)
    TIM2->CCER = (1U << 0);

    // CR1: ARPE=1 (auto-reload preload)
    TIM2->CR1 = (1U << 7);

    // EGR: UG=1 — force shadow register load
    TIM2->EGR = (1U << 0);

    // CR1: CEN=1 — start counter
    TIM2->CR1 |= (1U << 0);
}

void pwm_set_pulse_us(uint32_t pulse_us) {
    // Clamp to valid servo range
    if (pulse_us < 1000) pulse_us = 1000;
    if (pulse_us > 2000) pulse_us = 2000;
    TIM2->CCR1 = pulse_us;
}