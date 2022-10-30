/*
 * led.h
 *
 *  Created on: 28-Dec-2019
 *      Author: nieki
 */

#ifndef LED_H_
#define LED_H_
#include "stm32f03xx.h"

#define LED_GREEN  		9
#define LED_ORANGE 		10
#define LED_RED	  		11

#define DELAY_COUNT_1MS 		 1250U
#define DELAY_COUNT_1S  		(1000U * DELAY_COUNT_1MS)
#define DELAY_COUNT_500MS  		(5000U  * DELAY_COUNT_1MS)
#define DELAY_COUNT_250MS 		(20000U  * DELAY_COUNT_1MS)
#define DELAY_COUNT_125MS 		(20500U  * DELAY_COUNT_1MS)

void led_init_all(void);
void led_on(u8 led_no);
void led_off(u8 led_no);
void delay(u32 count);

#endif /* LED_H_ */
