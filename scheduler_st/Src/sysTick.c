/*
 ============================================================================
 Name        : scheduler_stm32f030c8t6.c
 Author      : Abdelzim Ahmed
 Version     :
 Copyright   : Your copyright notice
 Description :
 ============================================================================
 */
#include "sysTick.h"

sysTick_init(u32 tick)
{
	u32 load;

	load = (sysCLK/tick)-1;
	SYST_RVR &= ~(0x00ffffff);
	SYST_RVR |= load;

	SELECT_sysTick_CLK(clkMask);
	sysTickINT_ENABLE();
	sysTick_ENABLE();
}
