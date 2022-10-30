/*
 * App.c
 *
 *  Created on: Oct 24, 2022
 *      Author: a_a
 */

#include "App.h"

void App_init(void)
{
	// TODO;
	schedStack_init();
	tasksStack_init();
	led_init_all();
	sysTick_init(TICK_HZ);
	sp_using_psp();
}
void idle_task(void)
{
	//TODO
	while(1);
}
void task1(void)
{
	//TODO
	while(1)
	{
		led_on(LED_GREEN);
		delay(DELAY_COUNT_1S);
		led_off(LED_GREEN);
		delay(DELAY_COUNT_1S);
	}

}
void task2(void)
{
	//TODO
	while(1)
		{
			led_on(LED_ORANGE);
			delay(DELAY_COUNT_500MS);
			led_off(LED_ORANGE);
			delay(DELAY_COUNT_500MS);
		}

}
void task3(void)
{
	//TODO

	while(1)
	{
		led_on(LED_RED);
		delay(DELAY_COUNT_250MS);
		led_off(LED_RED);
		delay(DELAY_COUNT_250MS);
	}

}
