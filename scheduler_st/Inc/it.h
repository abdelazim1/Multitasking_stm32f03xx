/*
 * it.h
 *
 *  Created on: Oct 30, 2022
 *      Author: a_a
 */

#ifndef IT_H_
#define IT_H_

#include "scheduler.h"
void SysTick_Handler(void);
Naked void PendSV_Handler(void);


/* TODO
void HardFault_Handler(void);
*/

#endif /* IT_H_ */
