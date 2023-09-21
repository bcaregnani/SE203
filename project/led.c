#include<stdint.h>
#include"CMSIS/Device/ST/STM32L4xx/Include/stm32l475xx.h"
#include"led.h"




void led_init(void)
{
    // ENABLE CK Port B
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
    GPIOB->MODER = (GPIOB->MODER &~GPIO_MODER_MODE14_Msk ) | ( 0b1 << GPIO_MODER_MODE14_Pos); //MODE I/0 PORT B Pin 14
    // ENABLE CK PORT C
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN;

}


void led_g_on(void)
{
	GPIOB->BSRR = GPIO_BSRR_BS14;
}

void led_g_off(void)
{
	GPIOB->BSRR = GPIO_BSRR_BR14;
}


void led(enum state s)
{
    switch (s)
    {
    case 0: //LED_OFF both of them
        GPIOC->MODER = (GPIOC->MODER &~GPIO_MODER_MODE9_Msk) | ( 0b0 << GPIO_MODER_MODE9_Pos); // INPUT MODE IN GPIOC
        break;
    case 1: //LED_YELLOW ON   /   LED_BLUE OFF
        GPIOC->MODER = (GPIOC->MODER &~GPIO_MODER_MODE9_Msk) | ( 0b1 << GPIO_MODER_MODE9_Pos); // OUTPUT MODE IN GPIOC
        GPIOC->BSRR = (GPIOC->BSRR &~GPIO_BSRR_BS9_Msk) | (1<<GPIO_BSRR_BS9_Pos);
        break;
    case 2: //LED_BLUE ON     /   LED_YELLOW OFF
        GPIOC->MODER = (GPIOC->MODER &~GPIO_MODER_MODE9_Msk ) | ( 0b1 << GPIO_MODER_MODE9_Pos); // OUTPUT MODE IN GPIOC  
        GPIOC->BSRR = (GPIOC->BSRR &~GPIO_BSRR_BR9_Msk) | (0b1<<GPIO_BSRR_BR9_Pos) ;
        break;
    
    default:
        break;
    }
}
