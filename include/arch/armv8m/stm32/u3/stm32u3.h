/*
 * Phoenix-RTOS
 *
 * Operating system kernel
 *
 * STM32U3 basic peripherals control functions
 * Based on stm32u3c5xx.h by STMicroelectronics
 *
 * Copyright 2026 Apator Metrix
 * Authors: Mateusz Karcz
 *
 * This file is part of Phoenix-RTOS.
 *
 * %LICENSE%
 */

#ifndef _PH_ARCH_STM32U3_H_
#define _PH_ARCH_STM32U3_H_


#define PCTL_REBOOT_MAGIC 0xaa55aa55UL

/* Clock Enable Register relative to AHB1ENR1, encoded with device bit */
#define _PCTL_DEV(rcc_reg, pos) (((((rcc_reg) - 0x088) >> 2) << 5) | (pos))

/* STM32U3 device identifiers */
enum {
	pctl_gpdma1 = _PCTL_DEV(0x088, 0),
	pctl_adf1 = _PCTL_DEV(0x088, 3),
	pctl_hsp1 = _PCTL_DEV(0x088, 4),
	pctl_flash = _PCTL_DEV(0x088, 8),
	pctl_crc = _PCTL_DEV(0x088, 12),
	pctl_tsc = _PCTL_DEV(0x088, 16),
	pctl_ramcfg = _PCTL_DEV(0x088, 17),
	pctl_gtzc1 = _PCTL_DEV(0x088, 24),
	pctl_sram4 = _PCTL_DEV(0x088, 30),
	pctl_sram1 = _PCTL_DEV(0x088, 31),
	pctl_gpioa = _PCTL_DEV(0x08c, 0),
	pctl_gpiob = _PCTL_DEV(0x08c, 1),
	pctl_gpioc = _PCTL_DEV(0x08c, 2),
	pctl_gpiod = _PCTL_DEV(0x08c, 3),
	pctl_gpioe = _PCTL_DEV(0x08c, 4),
	pctl_gpiof = _PCTL_DEV(0x08c, 5),
	pctl_gpiog = _PCTL_DEV(0x08c, 6),
	pctl_gpioh = _PCTL_DEV(0x08c, 7),
	pctl_adc12 = _PCTL_DEV(0x08c, 10),
	pctl_dac1 = _PCTL_DEV(0x08c, 11),
	pctl_aes = _PCTL_DEV(0x08c, 16),
	pctl_hash = _PCTL_DEV(0x08c, 17),
	pctl_rng = _PCTL_DEV(0x08c, 18),
	pctl_pka = _PCTL_DEV(0x08c, 19),
	pctl_saes = _PCTL_DEV(0x08c, 20),
	pctl_ccb = _PCTL_DEV(0x08c, 21),
	pctl_sdmmc1 = _PCTL_DEV(0x08c, 27),
	pctl_sram2 = _PCTL_DEV(0x08c, 30),
	pctl_sram3 = _PCTL_DEV(0x08c, 31),
	pctl_octospi1 = _PCTL_DEV(0x090, 4),
	pctl_pwr = _PCTL_DEV(0x094, 2),
	pctl_tim2 = _PCTL_DEV(0x09c, 0),
	pctl_tim3 = _PCTL_DEV(0x09c, 1),
	pctl_tim4 = _PCTL_DEV(0x09c, 2),
	pctl_tim6 = _PCTL_DEV(0x09c, 4),
	pctl_tim7 = _PCTL_DEV(0x09c, 5),
	pctl_spi3 = _PCTL_DEV(0x09c, 8),
	pctl_spi4 = _PCTL_DEV(0x09c, 9),
	pctl_wwdg = _PCTL_DEV(0x09c, 11),
	pctl_iwdg = _PCTL_DEV(0x09c, 12), /* DBGMCU_APB1LFZR_DBG_IWDG_STOP */
	pctl_spi2 = _PCTL_DEV(0x09c, 14),
	pctl_usart2 = _PCTL_DEV(0x09c, 17),
	pctl_usart3 = _PCTL_DEV(0x09c, 18),
	pctl_uart4 = _PCTL_DEV(0x09c, 19),
	pctl_uart5 = _PCTL_DEV(0x09c, 20),
	pctl_i2c1 = _PCTL_DEV(0x09c, 21),
	pctl_i2c2 = _PCTL_DEV(0x09c, 22),
	pctl_i3c1 = _PCTL_DEV(0x09c, 23),
	pctl_crs = _PCTL_DEV(0x09c, 24),
	pctl_opamp = _PCTL_DEV(0x09c, 28),
	pctl_vref = _PCTL_DEV(0x09c, 29),
	pctl_rtcapb = _PCTL_DEV(0x09c, 30),
	pctl_i2c4 = _PCTL_DEV(0x0a0, 1),
	pctl_lptim2 = _PCTL_DEV(0x0a0, 5),
	pctl_fdcan = _PCTL_DEV(0x0a0, 9),
	pctl_tim1 = _PCTL_DEV(0x0a4, 11),
	pctl_spi1 = _PCTL_DEV(0x0a4, 12),
	pctl_tim8 = _PCTL_DEV(0x0a4, 13),
	pctl_usart1 = _PCTL_DEV(0x0a4, 14),
	pctl_tim12 = _PCTL_DEV(0x0a4, 15),
	pctl_tim15 = _PCTL_DEV(0x0a4, 16),
	pctl_tim16 = _PCTL_DEV(0x0a4, 17),
	pctl_tim17 = _PCTL_DEV(0x0a4, 18),
	pctl_sai1 = _PCTL_DEV(0x0a4, 21),
	pctl_usb1 = _PCTL_DEV(0x0a4, 24),
	pctl_i3c2 = _PCTL_DEV(0x0a4, 27),
	pctl_syscfg = _PCTL_DEV(0x0a8, 1),
	pctl_lpuart1 = _PCTL_DEV(0x0a8, 6),
	pctl_i2c3 = _PCTL_DEV(0x0a8, 7),
	pctl_lptim1 = _PCTL_DEV(0x0a8, 11),
	pctl_lptim3 = _PCTL_DEV(0x0a8, 12),
	pctl_lptim4 = _PCTL_DEV(0x0a8, 13),
	pctl_comp = _PCTL_DEV(0x0a8, 15),
	pctl_rtc = _PCTL_DEV(0x110, 15),
};


/* STM32U3 independent device clocks */
enum ipclks {
	pctl_ipclk_usart1sel = 0,
	pctl_ipclk_usart3sel,
	pctl_ipclk_uart4sel,
	pctl_ipclk_uart5sel,
	pctl_ipclk_i3c1sel,
	pctl_ipclk_i2c1sel,
	pctl_ipclk_i2c2sel,
	pctl_ipclk_i3c2sel,
	pctl_ipclk_spi2sel,
	pctl_ipclk_lptim2sel,
	pctl_ipclk_spi1sel,
	pctl_ipclk_systicksel,
	pctl_ipclk_fdcansel,
	pctl_ipclk_iclksel,
	pctl_ipclk_adf1sel,
	pctl_ipclk_spi3sel,
	pctl_ipclk_sai1sel,
	pctl_ipclk_spi4sel,
	pctl_ipclk_i2c4sel,
	pctl_ipclk_rngsel,
	pctl_ipclk_adcdacsel,
	pctl_ipclk_dac1shsel,
	pctl_ipclk_octospisel,
	pctl_ipclk_usart2sel,
	pctl_ipclk_lpuart1sel,
	pctl_ipclk_i2c3sel,
	pctl_ipclk_lptim34sel,
	pctl_ipclk_lptim1sel,
	pctl_ipclks_count
};


/* STM32U3 Interrupt numbers */
enum {
	wwdg_irq = 16,
	pvd_pvm_irq,
	rtc_irq,
	rtc_s_irq,
	tamp_irq,
	ramcfg_irq,
	flash_irq,
	flash_s_irq,
	gtzc_irq,
	rcc_irq,
	rcc_s_irq,
	exti0_irq,
	exti1_irq,
	exti2_irq,
	exti3_irq,
	exti4_irq,
	exti5_irq,
	exti6_irq,
	exti7_irq,
	exti8_irq,
	exti9_irq,
	exti10_irq,
	exti11_irq,
	exti12_irq,
	exti13_irq,
	exti14_irq,
	exti15_irq,
	iwdg_irq,
	saes_irq,
	gpdma1_ch0_irq,
	gpdma1_ch1_irq,
	gpdma1_ch2_irq,
	gpdma1_ch3_irq,
	gpdma1_ch4_irq,
	gpdma1_ch5_irq,
	gpdma1_ch6_irq,
	gpdma1_ch7_irq,
	adc1_irq,
	dac1_irq,
	fdcan1_it0_irq,
	fdcan1_it1_irq,
	tim1_brk_terr_ierr_irq,
	tim1_up_irq,
	tim1_trg_com_dir_idx_irq,
	tim1_cc_irq,
	tim2_irq,
	tim3_irq,
	tim4_irq,
	tim6_irq = 65,
	tim7_irq,
	tim12_irq,
	i3c1_ev_irq = 69,
	i3c1_er_irq,
	i2c1_ev_irq,
	i2c1_er_irq,
	i2c2_ev_irq,
	i2c2_er_irq,
	spi1_irq,
	spi2_irq,
	usart1_irq,
	usart2_irq,
	usart3_irq,
	uart4_irq,
	uart5_irq,
	lpuart1_irq,
	lptim1_irq,
	lptim2_irq,
	tim15_irq,
	tim16_irq,
	tim17_irq,
	comp_irq,
	usb_fs_irq,
	crs_irq,
	octospi1_irq = 92,
	hsp1_irq,
	sdmmc1_irq,
	gpdma1_ch8_irq = 96,
	gpdma1_ch9_irq,
	gpdma1_ch10_irq,
	gpdma1_ch11_irq,
	i2c3_ev_irq = 104,
	i2c3_er_irq,
	sai1_irq,
	tsc_irq = 108,
	aes_irq,
	rng_irq,
	fpu_irq,
	hash_irq,
	pka_irq,
	lptim3_irq,
	spi3_irq,
	i3c2_ev_irq,
	i3c2_er_irq,
	tim8_brk_terr_ierr_irq,
	tim8_up_irq,
	tim8_trg_com_dir_idx_irq,
	tim8_cc_irq,
	icache_irq = 123,
	lptim4_irq = 126,
	adf1_irq = 128,
	adc2_irq,
	fdcan2_it0_irq,
	fdcan2_it1_irq,
	i2c4_ev_irq,
	i2c4_er_irq,
	spi4_irq = 135,
	pwr_irq = 139,
	pwr_s_irq,
};


typedef struct {
	enum {
		pctl_set = 0,
		pctl_get,
	} action;

	enum {
		pctl_devclk = 0,
		pctl_cpuclk,
		pctl_ipclk, /* Independent peripheral clock settings (muxes and dividers) */
		pctl_reboot,
		pctl_dmaPermissions,
		pctl_cleanInvalDCache,
		pctl_cleanDCache,
		pctl_dmaLinkBaseAddr,
	} type;

	union {
		struct {
			int dev;              /* one of pctl_* enum values */
			unsigned int state;   /* State in Run and Sleep modes: 1 - clock enabled, 0 - clock disabled */
			unsigned int lpState; /* State in Sleep mode: 1 - enabled, 0 - disabled */
		} devclk;
		struct {
			unsigned int hz;
		} cpuclk;
		struct {
			int dev; /* one of pctl_gpdma* enum values */
			unsigned int channel;
			int privileged; /* 1 - set to privileged, 0 - no change, -1 - set to unprivileged */
			int secure;     /* 1 - set to secure, 0 - no change, -1 - set to non-secure */
			int lock;       /* 1 - lock from changes until reset, 0 - no change */
		} dmaPermissions;
		struct {
			int dev; /* one of pctl_gpdma* enum values */
			unsigned int channel;
			unsigned int addr;
		} dmaLinkBaseAddr;
		struct {
			unsigned int ipclk;
			unsigned int setting;
		} ipclk;
		struct {
			unsigned int magic;
			unsigned int reason;
		} reboot;
		struct {
			void *addr;
			unsigned int sz;
		} opDCache;
	};
} __attribute__((packed)) platformctl_t;


#endif
