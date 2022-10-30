/*
 * scheduler.h
 *
 *  Created on: Oct 19, 2022
 *      Author: a_a
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include "stm32f03xx.h"
#include "cortex.h"
#include "App.h"

extern u32 gTickCount;

#define DUMMY_XPSR  			(0x01000000U) //Rest value == cortex-m4 generic user guide -> programmers Model -> core registers
#define EXC_RETURN				(0xFFFFFFFDU)

#define TASK_READY_STATE  		(0x00U)
#define TASK_BLOCKED_STATE  	(0XFFU)

typedef struct task_TCB
{
	u32 psp_value;
	u32 block_count;
	u32 current_state;
	void (*task_handler)(void);

}TCB_T;

void tasksStack_init(void);
Naked void schedStack_init();
u32 get_psp_value(void);
void save_psp_value(u32 current_psp_value);
void task_delay(u32 tick_count);
void unblock_tasks(void);

void update_next_task(void);
Naked void sp_using_psp(void);


#endif /* SCHEDULER_H_ */
