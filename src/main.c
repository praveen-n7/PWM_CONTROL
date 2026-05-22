#include "stm32f4xx.h"
#include "uart.h"         // your existing driver
#include "timer_pwm.h"
#include "systick.h"
#include <stdio.h>

static char uart_buf[64];

// angle (0-180) to pulse width in microseconds
static uint32_t angle_to_us(uint32_t angle) {
    return 1000 + (angle * 1000 / 180);
}

int main(void) {
    systick_init();
    uart2_init(115200);      // your existing UART driver
    pwm_init();

    uart2_send_string("Project 3: PWM Servo Sweep\r\n");

    while (1) {
        // Sweep 0 -> 180 in 5-degree steps
        for (int angle = 0; angle <= 180; angle += 5) {
            uint32_t pulse = angle_to_us(angle);
            pwm_set_pulse_us(pulse);

            int len = snprintf(uart_buf, sizeof(uart_buf),
                "Angle: %3d deg  Pulse: %4lu us  CCR1: %4lu\r\n",
                angle, (unsigned long)pulse, (unsigned long)TIM2->CCR1);
            for (int i = 0; i < len; i++)
                uart2_send_char(uart_buf[i]);

            delay_ms(20);
        }

        // Sweep 180 -> 0
        for (int angle = 180; angle >= 0; angle -= 5) {
            uint32_t pulse = angle_to_us(angle);
            pwm_set_pulse_us(pulse);
            delay_ms(20);
        }
    }
}