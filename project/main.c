#include"matrix.h"
#include"led.h"
#include"clocks.h"
#include"uart.h"
#include"irq.h"
#include"buttons.h"
#include"timer.h"
#include"CMSIS/Device/ST/STM32L4xx/Include/stm32l475xx.h"
#include<stdint.h>



uint8_t main()
{   
    clocks_init();
    irq_init();
    //led_init();
    timer_init(2080); //time in us
    //button_init();
    //led_init();
    uart_init(38400);
    


    /*
    clocks_init();
    led_init();
    while (1)
    {
        led_g_on();
        for (int i=0; i<20000000; i++)
            asm volatile("nop");
        led_g_off();
        for (int i=0; i<20000000; i++)
            asm volatile("nop");
        led(LED_YELLOW);
        for (int i=0; i<20000000; i++)
            asm volatile("nop");
        led(LED_BLUE);
        for (int i=0; i<20000000; i++)
            asm volatile("nop");
        led(LED_OFF);
        for (int i=0; i<20000000; i++)
            asm volatile("nop");
        
       
    }
    */   

    /*
    while (1)
        uart_putchar(uart_getchar());
    */

    /*
   const char * s = "Hello Toto";
   uart_puts(s);
   */

    /*
    while (1)
    {
        checksum();
    };
    */

    /*
    matrix_init();
    show_image();
    */
    
    uart_irq_led_init();
    matrix_init();
    while(1);
    
    
    return 0;
}