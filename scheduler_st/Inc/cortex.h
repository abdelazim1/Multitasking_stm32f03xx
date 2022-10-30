/*
 * cortex.h
 *
 *  Created on: Oct 28, 2022
 *      Author: a_a
 */

#ifndef CORTEX_H_
#define CORTEX_H_

#include "stm32f03xx.h"

#define INTERRUPT_DISABLE()  do{__asm volatile ("MOV R0,#0x1"); asm volatile("MSR PRIMASK,R0"); } while(0)

#define INTERRUPT_ENABLE()  do{__asm volatile ("MOV R0,#0x0"); asm volatile("MSR PRIMASK,R0"); } while(0)


#endif /* CORTEX_H_ */
