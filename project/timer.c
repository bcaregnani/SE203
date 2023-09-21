#include"CMSIS/Device/ST/STM32L4xx/Include/stm32l475xx.h"
#include"irq.h"
#include"led.h"
#include"matrix.h"
#include"uart.h"

extern uint8_t _binary_image_raw_start;



void timer_init(int max_us)
{
    RCC->APB1ENR1 |= RCC_APB1ENR1_TIM2EN; // Enable clock for TIM2
    TIM2->SR &= 0x0000;  // Reset all flags
    TIM2->CNT &= ~TIM_CNT_CNT; // Reset counter
    TIM2->CR1 = (TIM2->CR1 &~TIM_CR1_CMS ) | ( 0b00 << TIM_CR1_CMS_Pos);  //set TM2 edge-aligned mode
    TIM2->CR1 = (TIM2->CR1 &~TIM_CR1_DIR_Msk ) | ( 0 << TIM_CR1_DIR_Pos); //set TM2 as upcounter
    //TIM2->CR1 = (TIM2->CR1 &~TIM_CR1_ARPE ) | ( 1 << TIM_CR1_ARPE_Pos); // enable auto-reload register
    TIM2->PSC = (TIM2->PSC &~TIM_PSC_PSC ) | ( 79 << TIM_PSC_PSC_Pos);  // prescale TIM2 clock 79+1 (with reference to SYSCLK)
    TIM2->ARR = (TIM2->ARR &~TIM_ARR_ARR ) | ( max_us << TIM_ARR_ARR_Pos); //set TIM2 auto reload register
    TIM2->DIER = (TIM2->DIER &~TIM_DIER_UIE ) | ( 1 << TIM_DIER_UIE_Pos);  //enable update interrupt

    NVIC_EnableIRQ(TIM2_IRQn);

    TIM2->CR1 |= TIM_CR1_CEN; // enable clock 

}




void TIM2_IRQHandler()
{

    /*
    if ((GPIOB->ODR & GPIO_ODR_OD14))
        led_g_off();
    else
        led_g_on();
    */

    
    static uint8_t row=7;
    
    static const rgb_color * watch = (rgb_color *) frames; //&_binary_image_raw_start

    mat_set_row(row,watch);
    watch = watch + 8;
    if (row==0)
        {
            row=7;
            watch = (rgb_color *) frames;  //&_binary_image_raw_start
        }
        else
        {
            row--;
        }
    
    
    
    TIM2->SR &= 0x0000;  // Reset all flags
}



