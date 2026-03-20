/*
 * Phoenix-RTOS
 *
 * Operating system kernel
 *
 * Configuration file for STM32U3
 *
 * Copyright 2021, 2025 Phoenix Systems
 * Copyright 2026 Apator Metrix
 * Author: Hubert Buczynski, Jacek Maksymowicz, Mateusz Karcz
 *
 * This file is part of Phoenix-RTOS.
 *
 * %LICENSE%
 */

#ifndef _PH_HAL_CONFIG_H_
#define _PH_HAL_CONFIG_H_


#ifndef __ASSEMBLY__
#include "hal/types.h"
#include "include/arch/armv8m/stm32/syspage.h"
#include "include/syspage.h"
#include "hal/armv8m/stm32/stm32.h"
#include "hal/armv8m/stm32/stm32-timer.h"

#define SIZE_INTERRUPTS 141U

/* Constants for configuring which TIM peripheral is used as system timer */
#define TIM_SYSTEM_BASE ((void *)0x50001400UL) /* TIM7 base address */
#define TIM_SYSTEM_PCTL pctl_tim7
#define TIM_SYSTEM_IRQ  tim7_irq
#define TIM_SYSTEM_FREQ (12UL * 1000000UL) /* Frequency in Hz */

#define HAL_NAME_PLATFORM "STM32U3 "

#endif

#endif
