/*
 * schedular.h
 *
 *  Created on: Oct 15, 2022
 *      Author: a_a
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_

#include <stm32f03xx.h>


/* SysTick timer clock source */
#define sysTick_REFCLK    				(0<<2) //external clock
#define sysTick_PROSCLK					(1<<2) //processor clock
#define clkMask							(sysTick_PROSCLK)

#define SELECT_sysTick_CLK(clkmask) 	(SYST_CSR |=clkmask)

#define sysTick_ENABLE()				(SYST_CSR |=0x01)
#define sysTickINT_ENABLE()				(SYST_CSR |=0x02)

void sysTick_init(u32 tick);

#endif /* SYSTICK_H_ */
