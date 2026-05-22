#ifndef TIMER_PWM_H
#define TIMER_PWM_H
#include <stdint.h>

void pwm_init(void);
void pwm_set_pulse_us(uint32_t pulse_us);

#endif