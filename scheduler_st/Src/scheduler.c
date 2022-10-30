/*
 * scheduler.c
 *
 *  Created on: Oct 19, 2022
 *      Author: a_a
 */


#include "scheduler.h"

u8 current_task = 1;
u32 schedStart = sched_start;
u32 gTickCount = 0;

TCB_T user_tasks[MAX_TASKS];

void tasksStack_init(void)
{
	user_tasks[0].current_state = TASK_READY_STATE;
	user_tasks[1].current_state = TASK_READY_STATE;
	user_tasks[2].current_state = TASK_READY_STATE;
	user_tasks[3].current_state = TASK_READY_STATE;

	/*TODO
	 * for (u8 i = 0; i<MAX_TASKS; i++)
	 * {
	 *		user_tasks[i].current_state = TASK_READY_STATE;
	 * }
	 */

	/*
	 * TODO
	 * Generic pointer & function pointer
	 */
	user_tasks[0].psp_value = idleTask_start;
	user_tasks[1].psp_value = task1_start;
	user_tasks[2].psp_value = task2_start;
	user_tasks[3].psp_value =task3_start ;

	user_tasks[0].task_handler = idle_task;
	user_tasks[1].task_handler = task1;
	user_tasks[2].task_handler = task2;
	user_tasks[3].task_handler = task3;

	u32 *pPSP;
	for (u8 i = 0; i<MAX_TASKS; ++i)
	{
		pPSP = (u32*)user_tasks[i].psp_value;

		pPSP--;
		*pPSP = DUMMY_XPSR;

		/* PC */
		pPSP--;
		*pPSP = (u32) user_tasks[i].task_handler;

		/* LR */
		pPSP--;
		*pPSP = EXC_RETURN;

		for(u8 j = 0 ; j < 13 ; j++)
		{
					pPSP--;
				    *pPSP = 0;

		}
		user_tasks[i].psp_value = (u32)pPSP;
	}
}
Naked void schedStack_init(void)
{
	__asm __vo("MSR MSP,%0": :"l" (schedStart) :);
	__asm __vo("BX LR");
}

u32 get_psp_value(void)
{
	return user_tasks[current_task].psp_value;
}

void save_psp_value(u32 current_psp_value)
{
	user_tasks[current_task].psp_value = current_psp_value;
}

void task_delay(u32 tick_count)
{
	//disable interrupt
	INTERRUPT_DISABLE();

	if(current_task)
	{
	   user_tasks[current_task].block_count = gTickCount + tick_count;
	   user_tasks[current_task].current_state = TASK_BLOCKED_STATE;
	   ICSR |= ( 1 << 28);   //pend pendsv
	}

	//enable interrupt
	INTERRUPT_ENABLE();
}
void unblock_tasks(void)
{
	for(u32 i = 1 ; i < MAX_TASKS ; i++)
	{
		if(user_tasks[i].current_state != TASK_READY_STATE)
		{
			if(user_tasks[i].block_count == gTickCount)
			{
				user_tasks[i].current_state = TASK_READY_STATE;
			}
		}

	}
}



void update_next_task(void)
{
	int state = TASK_BLOCKED_STATE;

	for(int i= 0 ; i < (MAX_TASKS) ; i++)
	{
		current_task++;
	    current_task %= MAX_TASKS;
		state = user_tasks[current_task].current_state;
		if( (state == TASK_READY_STATE) && (current_task != 0) )
			break;
	}

	if(state != TASK_READY_STATE)
		current_task = 0;
}

Naked void sp_using_psp(void)
{
    /* initialize the PSP with TASK1 stack start address */
	__asm __vo ("PUSH {LR}"); 			//preserve LR which connects back to main()
	__asm __vo ("BL get_psp_value");
	__asm __vo ("MSR PSP,R0"); 			//initialize psp
	__asm __vo ("POP {PC}");  			//pops back LR value

	/* change SP to PSP using CONTROL register */
	__asm __vo ("MOV R0,#0X02");    	  //control register value
	__asm __vo ("MSR CONTROL,R0");
	__asm __vo ("BX LR");
}



















