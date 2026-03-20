/*
 * Phoenix-RTOS
 *
 * Operating system kernel
 *
 * Configuration file dispatch for STM32 ARMv8-M MCUs
 *
 * Copyright 2026 Apator Metrix
 * Author: Mateusz Karcz
 *
 * This file is part of Phoenix-RTOS.
 *
 * %LICENSE%
 */

#if defined(__CPU_STM32N6)
#include "n6/config.h"
#elif defined(__CPU_STM32U3)
#include "u3/config.h"
#else
#error "Unsupported platform"
#endif
