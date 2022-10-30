/*
 * config.h
 *
 *  Created on: Oct 24, 2022
 *      Author: a_a
 */

#ifndef CONFIG_H_
#define CONFIG_H_

#include "stm32f03xx.h"

#define sysCLK					(8000000U)
#define TICK_HZ 				(1000U)

#define TASK_STACK_SIZE     	(1024U)
#define SCHED_STACK_SIZE        (1024U)

#define MAX_TASKS				(3U)

#define idleTask_start			(SRAM_ENDADD)
#define task1_start				((SRAM_ENDADD)-(1* TASK_STACK_SIZE))
#define task2_start				((SRAM_ENDADD)-(2* TASK_STACK_SIZE))
#define task3_start				((SRAM_ENDADD)-(3* TASK_STACK_SIZE))

#define sched_start				((SRAM_ENDADD)-(4* TASK_STACK_SIZE))



#endif /* CONFIG_H_ */
