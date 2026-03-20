/*
 * Phoenix-RTOS
 *
 * Operating system kernel
 *
 * Low-level initialization for Cortex-M33 (ARMv8) on STM32U3
 *
 * Copyright 2026 Apator Metrix
 * Author: Mateusz Karcz
 *
 * This file is part of Phoenix-RTOS.
 *
 * %LICENSE%
 */

#define CORTEXM33_EXT_INTERRUPTS 125
#define CORTEXM33_PLATFORM_INIT  _stm32_init

#include <hal/armv8m/_init-m33.S>
