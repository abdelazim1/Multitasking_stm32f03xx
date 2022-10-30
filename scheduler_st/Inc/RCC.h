/*
 * RCC.H
 *
 *  Created on: Oct 17, 2022
 *      Author: a_a
 */

#ifndef RCC_H_
#define RCC_H_

/*
 * remember clear then set
 */

#include "stm32f03xx.h"

/* RCC-CRbits*/
#define HSEON				(1<<16)
#define HSERDY_FLAG			(1<<17)


/* RCC-CFGRbits*/
#define SW_HSE				(0x01)
#define SW_PLL				(0x03)

/*HSE ENABLE AND SELECT*/
#define HSE_EN()			(RCC_CR |= HSEON)

#define HCLK_PRESCALER_2	(0x80)

#define PCLK_PRESCALER_2	(1<<10)



/* TODO : update function to switch between resources, now configerd to select HSE*/
void clk_source(void);


#endif /* RCC_H_ */
