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

/* Constants for configuring which LPTIM peripheral is used as system timer */
#define LPTIM_SYSTEM_BASE      ((void *)0x50009400UL) /* LPTIM2 base address */
#define LPTIM_SYSTEM_IRQ       lptim2_irq
#define LPTIM_SYSTEM_PCTL      pctl_lptim2
#define LPTIM_SYSTEM_IPCLK_SEL pctl_ipclk_lptim2sel
#define LPTIM_SYSTEM_IPCLK_VAL 1 /* LSI */
#define LPTIM_SYSTEM_INPUT     32000UL /* LSI input frequency in Hz */
#define LPTIM_SYSTEM_CYCLE_MS  16000UL /* 16 s */

#define HAL_NAME_PLATFORM "STM32U3 "

#endif

#endif
