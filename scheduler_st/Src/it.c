/*
 * it.c
 *
 *  Created on: Oct 28, 2022
 *      Author: a_a
 */
#include "it.h"

void SysTick_Handler(void)
{
	//TODO
	/*
	 * remember clear flag
	 */
	gTickCount++;
	unblock_tasks();
	//pend the pendsv exception == direct
	 ICSR |= ( 1 << 28);

}

Naked void PendSV_Handler(void)
{

	/*Save the context of current task */

	//1. Get current running task's PSP value
	__asm __vo("MRS R0,PSP");
	//2. Using that PSP value to store SF2( R4 to R11)
	__asm __vo("STM R0!,{R4-R7}");

	__asm __vo("PUSH {LR}");

	//3. Save the current value of PSP
    __asm __vo("BL save_psp_value");



	/*Retrieve the context of next task */

	//1. Decide next task to run
    __asm __vo("BL update_next_task");

	//2. get its past PSP value
	__asm __vo ("BL get_psp_value");

	//3. Using that PSP value to retrieve SF2(R4 to R11)
	__asm __vo ("LDMIA R0!,{R4-R7}");

	//4. update PSP and exit
	__asm __vo("MSR PSP,R0");

	__asm __vo("POP {PC}");

	__asm __vo("BX LR");



}


/* TODO
void HardFault_Handler(void)
{
	printf("Exception : Hardfault\n");
	while(1);
}
*/
