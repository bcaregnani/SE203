#include"CMSIS/Device/ST/STM32L4xx/Include/stm32l475xx.h"
#include<stddef.h>
#include"uart.h"



void uart_init(int baudrate)
{
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN; // Turn on clock of GPIOB in bus AHB2
    GPIOB->MODER = (GPIOB->MODER &~GPIO_MODER_MODE6_Msk ) | ( 0b10 << GPIO_MODER_MODE6_Pos); // set PB6 like mode AF
    GPIOB->MODER = (GPIOB->MODER &~GPIO_MODER_MODE7_Msk ) | ( 0b10 << GPIO_MODER_MODE7_Pos); // set PB7 like mode AF
    GPIOB->AFR[0] = (GPIOB->AFR[0] &~GPIO_AFRL_AFSEL6_Msk) | (0b0111 << GPIO_AFRL_AFSEL6_Pos); // PB6 as AF7 mode (USART1_TX)
    GPIOB->AFR[0] = (GPIOB->AFR[0] &~GPIO_AFRL_AFSEL7_Msk) | (0b0111 << GPIO_AFRL_AFSEL7_Pos); // PB7 as AF7 mode (USART1_RX)
    
    RCC->APB2ENR |= RCC_APB2ENR_USART1EN; // Turn on clock of USART1 in bus APB2
    RCC->CCIPR = (RCC->CCIPR &~RCC_CCIPR_USART1SEL_Msk) | ( 0b00 << RCC_CCIPR_USART1SEL_Pos); // Select type of clock PCLK for USART1

    RCC->APB2RSTR |= RCC_APB2RSTR_USART1RST; // reset USART1 register
    RCC->APB2RSTR = (RCC->APB2RSTR &~RCC_APB2RSTR_USART1RST_Msk) | (0b0 << RCC_APB2RSTR_USART1RST_Pos); // set USART1 register
    
    // note: next configurations needs to be done before USART enable, located at the end
    USART1->BRR = (USART1->BRR &~USART_BRR_DIV_FRACTION_Msk) | (80000000/baudrate << USART_BRR_DIV_FRACTION_Pos); //set bps
    USART1->CR1 = (USART1->CR1 &~USART_CR1_OVER8_Msk) | (0b0<<USART_CR1_OVER8_Pos); // set oversampling16 mode for USART1 OVER8=0
    USART1->CR1 = (USART1->CR1 &~USART_CR1_M1_Msk) | (0b0<<USART_CR1_M1_Pos) | (0<<USART_CR1_M0_Pos); // set M[1] in 0 and M[0] in 0, for 8 bits data length
    USART1->CR1 = (USART1->CR1 &~USART_CR1_PCE_Msk) | (0b0<<USART_CR1_PCE_Pos); //sets parity control disabled
    USART1->CR2 = (USART1->CR2 &~USART_CR2_STOP_Msk) | (0b00<<USART_CR2_STOP_Pos); //sets stop bits to 1 bit
    USART1->CR1 |= USART_CR1_UE; // USART enable
    USART1->CR1 |= USART_CR1_RE; // USART enable Receiver
    USART1->CR1 |= USART_CR1_TE; // USART enable Transmitter

}


void uart_putchar(uint8_t c)
{
    while (!(USART1->ISR & USART_ISR_TXE));
    USART1->TDR = (USART1->TDR &~USART_TDR_TDR_Msk) | (c<<USART_TDR_TDR_Pos);
}

uint8_t uart_getchar()
{
    while (!(USART1->ISR & USART_ISR_RXNE));
    return (uint8_t) (USART1->RDR & USART_RDR_RDR);
}

void uart_puts(const char *s)
{
    while (*s)
    {
        uart_putchar(*s++);
    }
    uart_putchar('\r');
    uart_putchar('\n');
}

void uart_gets(char *s, size_t size)
{
    size_t i;
    for ( i = 0; i < size; i++)
    {
        s[i] = uart_getchar();

        if(s[i] == '\r')
        {
            break;
        }
    }
    s[i+1] = '\0';
}

uint32_t sum;

void checksum()
{
    while (!(USART1->ISR & USART_ISR_RXNE_Msk))
        sum += uart_getchar();
}

// Setting for interruption
void uart_irq_led_init  (void)
{

    //Managing the external interrupt line connection to the GPIO, in this case PB7
    //SYSCFG->EXTICR[1] = (SYSCFG->EXTICR[1] &~SYSCFG_EXTICR2_EXTI7_Msk ) | (SYSCFG_EXTICR2_EXTI7_PB);

    USART1->CR1 |= USART_CR1_RXNEIE; // RXNE Interrupt Enable
    
    //enable nvic irq
    NVIC_EnableIRQ(USART1_IRQn);


}


uint8_t frames[192];


void USART1_IRQHandler()
{

    if (USART1->ISR & USART_ISR_ORE || USART1->ISR & USART_ISR_FE) // Overrun error or Framing error
    {
        USART1->RQR |= USART_RQR_RXFRQ_Msk; // The RXNE flag clear
        USART1->ICR |= USART_ICR_FECF_Msk; // The FE bit is reset 
        return; // return and wait for next
    }

    static uint8_t i;
    uint8_t aux = uart_getchar();
    if(aux == 0xFF || i >= 192)
    {
        i = 0;
        return;
    }  

    frames[i++] = aux;
}


