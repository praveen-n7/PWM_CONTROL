# STM32F407 Bare-Metal PWM Servo Control

## Project Overview

Implemented a Timer, PWM and SysTick driver from scratch on STM32F407VG using CMSIS and direct register-level programming.

Generated a 50Hz PWM signal using TIM2 to control an SG90 servo motor while using SysTick interrupts for precise timing and UART telemetry for runtime monitoring.

---

## Features

- Bare-metal PWM driver
- TIM2 PWM Mode 1
- Servo position control
- SysTick interrupt framework
- UART telemetry
- NVIC configuration
- Logic analyzer validation

---

## Hardware

- STM32F407G-DISC1
- SG90 Servo Motor
- FT232RL USB-UART Converter
- Logic Analyzer

---

## Software & Tools

- Embedded C
- CMSIS
- ARM GNU Toolchain
- GNU Make
- OpenOCD
- PulseView

---

## Project Architecture

TIM2
|
PWM Signal
|
SG90 Servo

SysTick
|
Delay Framework

UART
|
Debug Output

---

## Results

- Generated stable 50Hz PWM signal
- Servo sweep from 0° to 180°
- Verified pulse width using Logic Analyzer
- Real-time angle telemetry over UART

---

## Key Learnings

- Timer peripherals
- PWM generation
- Interrupt handling
- SysTick configuration
- Hardware debugging
