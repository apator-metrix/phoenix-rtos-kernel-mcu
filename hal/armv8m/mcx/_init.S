/*
 * Phoenix-RTOS
 *
 * Operating system kernel
 *
 * Low-level initialization for Cortex-M33 (ARMv8) on MCXN94x
 *
 * Copyright 2012, 2016-2017, 2022, 2024 Phoenix Systems
 * Copyright 2026 Apator Metrix
 * Author: Jacek Popko, Pawel Pisarczyk, Jakub Sejdak, Aleksander Kaminski, Damian Loewnau, Mateusz Karcz
 *
 * This file is part of Phoenix-RTOS.
 *
 * %LICENSE%
 */

#define CORTEXM33_EXT_INTERRUPTS 156
#define CORTEXM33_PLATFORM_INIT  _mcxn94x_init

#include <hal/armv8m/_init-m33.S>
