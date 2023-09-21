#include"CMSIS/Device/ST/STM32L4xx/Include/stm32l4xx.h"
#include"CMSIS/Device/ST/STM32L4xx/Include/stm32l475xx.h"
#include"buttons.h"
#include"led.h"
#include<stdio.h>

void button_init(void)
{
    // ENABLE CK PORT C
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN;

    GPIOC->MODER &=~GPIO_MODER_MODE13_Msk;//MODE I/0 PORT C Pin 13

    //Managing the external interrupt line connection to the GPIO, in this case PC14
    SYSCFG->EXTICR[3] = (SYSCFG->EXTICR[3] &~SYSCFG_EXTICR4_EXTI13_Msk ) | (SYSCFG_EXTICR4_EXTI13_PC);

    //Hardware interuption selection, To configure a line as an interrupt source

    //Configure the mask bit in the EXTI_IMR register
    EXTI->IMR1 |=  EXTI_IMR1_IM13;

    // Configure the Trigger Selection bits of the Interrupt line

    //Configure Rising trigger selection register 1, disable rising trigger
    EXTI->RTSR1 &= ~EXTI_RTSR1_RT13;
    //Configure Falling trigger selection register 1, enable rising trigger
    EXTI->FTSR1 |=  EXTI_FTSR1_FT13;
    //enable nvic irq
    NVIC_EnableIRQ(EXTI15_10_IRQn);


}


void EXTI15_10_IRQHandler()
{
    EXTI->PR1 |= EXTI_PR1_PIF13; //disable interruption
    if ((GPIOB->ODR & GPIO_ODR_OD14))
    led_g_off();
    else
    led_g_on();

}