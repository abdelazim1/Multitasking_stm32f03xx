/*
 * RCC.C
 *
 *  Created on: Oct 17, 2022
 *      Author: a_a
 */
#include "RCC.h"

void clk_source_HSE(void)
{
	// TODO :update function to switch between resources, now configerd to select HSE*/
	HSE_EN();
	while(!(RCC_CR & (HSERDY_FLAG)));
	RCC_CFGR &= ~(0x03);
	RCC_CFGR |= SW_HSE;
}
