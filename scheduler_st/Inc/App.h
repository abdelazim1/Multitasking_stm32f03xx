/*
 * App.h
 *
 *  Created on: Oct 24, 2022
 *      Author: a_a
 */

#ifndef APP_H_
#define APP_H_

#include "cortex.h"
#include "sysTick.h"
#include "scheduler.h"
#include "led.h"

void App_init(void);
void idle_task(void);
void task1(void);
void task2(void);
void task3(void);


#endif /* APP_H_ */
