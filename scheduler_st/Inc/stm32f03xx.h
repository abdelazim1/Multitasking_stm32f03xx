/*
 * DEVICE_HEADER.h
 *
 *  Created on: Oct 15, 2022
 *      Author: Abdelzim Ahmed
 */

#ifndef DEVICE_HEADER_H_
#define DEVICE_HEADER_H_

#include "config.h"
#include "STD_TYPE.h"

#define SARM_SIZE			((8)*(1024))
#define SRAM_BASEADD		(0x20000000U)
#define SRAM_ENDADD			(0x20001FFFU)   //  SRAM_BASEADD (HEX) + ((8*1024)-1) HEX


/* RCC REGISTERS */
#define RCC_CR				*((__vo u32 *)0x40021000)
#define RCC_CFGR			*((__vo u32 *)0x40021004)
#define RCC_AHBENR			*((__vo u32 *)0x40021014)

/* systick timer */
#define SYST_CSR			*((__vo u32 *)0xE000E010)
#define SYST_RVR			*((__vo u32 *)0xE000E014)

#define GPIOA_MODER			*((__vo u32 *)0x48000000)
#define GPIOx_ODR			*((__vo u32 *)0x48000014)


/* Interrupt Control and State Register */
#define ICSR 				*((__vo u32 *)0xE000ED04)


//							*((__vo u32 *)0xE000E010)
#endif /* DEVICE_HEADER_H_ */
