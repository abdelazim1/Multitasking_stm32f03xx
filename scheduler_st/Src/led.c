
#include<stdint.h>
#include "led.h"



void delay(u32 count)
{
  for(u32 i = 0 ; i < count ; i++);
}

void led_init_all(void)
{

	RCC_AHBENR |= ( 1 << 17);
	//configure LED_GREEN
	GPIOA_MODER |= ( 1 << (2 * LED_GREEN));
	GPIOA_MODER |= ( 1 << (2 * LED_ORANGE));
	GPIOA_MODER |= ( 1 << (2 * LED_RED));

    led_off(LED_GREEN);
    led_off(LED_ORANGE);
    led_off(LED_RED);


}

void led_on(u8 led_no)
{
  GPIOx_ODR |= ( 1 << led_no);

}

void led_off(u8 led_no)
{
	  GPIOx_ODR &= ~( 1 << led_no);

}


