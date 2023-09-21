#include"CMSIS/Device/ST/STM32L4xx/Include/stm32l475xx.h"
#include"CMSIS/Device/ST/STM32L4xx/Include/stm32l4xx.h"
#include"matrix.h"
#include"uart.h"


extern uint8_t _binary_image_raw_start;




//ROWS CONTROL

void deactivate_rows()
{
    ROW0(0);
    ROW1(0);
    ROW2(0);
    ROW3(0);
    ROW4(0);
    ROW5(0);
    ROW6(0);
    ROW7(0);
}
void activate_row(uint8_t row)
{
    switch (row)
    {
    case 0:
        ROW0(1);
        break;
    case 1:
        ROW1(1);
        break;
    case 2:
        ROW2(1);
        break;
    case 3:
        ROW3(1);
        break;
    case 4:
        ROW4(1);
        break;
    case 5:
        ROW5(1);
        break;
    case 6:
        ROW6(1);
        break;
    case 7:
        ROW7(1);
        break;

    default:
        break;
    };
}


//CONTROL DM163

void send_byte(uint8_t val, uint8_t bank)
{
    SB(bank);
    uint8_t j;
    if (bank==1)
        j=7;
    else
        j=5;
    for (int8_t i = j; i >= 0; i--)
        {
            if (  (val & (1<<i)) == 1<<i )
                SDA(1)
            else
                SDA(0);
            pulse_SCK;
        }
}




void mat_set_row(int row, const rgb_color *val)
{

    deactivate_rows();

    for (uint8_t i = 0; i <= 7 ; i++)
    {
        send_byte(val->b,1);
        send_byte(val->g,1);
        send_byte(val->r,1);
        val++;                     
    };
    
    pulse_LAT;
    activate_row(row);
    
}


void init_bank0()
{
    for (uint8_t i = 0; i < 24; i++)
        send_byte(255,0);
    pulse_LAT;
}





void test_pixels()
{   
    //Define degraded colors blue, green, red
    rgb_color blue[8];
    rgb_color green[8];
    rgb_color red[8];
    uint8_t full=255;
    for (uint8_t i = 0; i <= 7; i++)
    {
        (blue[i]).r=0;
        (blue[i]).g=0;
        (blue[i]).b=full>>i;
    };

    for (uint8_t i = 0; i <= 7; i++)
    {
        (green[i]).r=0;
        (green[i]).g=full>>i;
        (green[i]).b=0;
    };

    for (uint8_t i = 0; i <= 7; i++)
    {
        (red[i]).r=full>>i;
        (red[i]).g=0;
        (red[i]).b=0;
    };
    
    const rgb_color * pblue = &blue[0];
    const rgb_color * pgreen = &green[0];
    const rgb_color * pred = &red[0];

    while (1)
    {

        mat_set_row(0, pblue);

        for (int i=0; i<100; i++) //wait
            asm volatile("nop"); 

        mat_set_row(1, pgreen);

        for (int i=0; i<100; i++) //wait
            asm volatile("nop"); 

        mat_set_row(2, pred);

        for (int i=0; i<100; i++) //wait
            asm volatile("nop"); 
        
        mat_set_row(3, pblue);

        for (int i=0; i<100; i++) //wait
            asm volatile("nop"); 

        mat_set_row(4, pgreen);

        for (int i=0; i<100; i++) //wait
            asm volatile("nop"); 
        
        mat_set_row(5, pred);

        for (int i=0; i<100; i++) //wait
            asm volatile("nop"); 

        mat_set_row(6, pblue);

        for (int i=0; i<100; i++) //wait
            asm volatile("nop"); 
        
        mat_set_row(7, pgreen);

        for (int i=0; i<100; i++) //wait
            asm volatile("nop");    
        
    }
    
}




void show_image()
{
    while (1)
    {
        const rgb_color * watch = (rgb_color *) &_binary_image_raw_start;

        for (int8_t row = 7; row >= 0; row--)   
        {
            mat_set_row(row,watch);
            for (int i=0; i<100; i++) //wait
                asm volatile("nop");
        
            watch = watch + 8;
        };
        
        watch = (rgb_color *) &_binary_image_raw_start;
    };
}




void matrix_init()
{
    //CLOCKS ENABLES
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN; //Enable clock port A
    SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOAEN);
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN; //Enable clock port B
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN; //Enable clock port C


    //SET OUTPUT MODE OF PINS

    //PORT A
    GPIOA->MODER = (GPIOA->MODER &~ GPIO_MODER_MODE2) | ( 0b1 << GPIO_MODER_MODE2_Pos); //Pin 2
    GPIOA->MODER = (GPIOA->MODER &~ GPIO_MODER_MODE3) | ( 0b1 << GPIO_MODER_MODE3_Pos); //Pin 3
    GPIOA->MODER = (GPIOA->MODER &~ GPIO_MODER_MODE4) | ( 0b1 << GPIO_MODER_MODE4_Pos); //Pin 4
    GPIOA->MODER = (GPIOA->MODER &~ GPIO_MODER_MODE5) | ( 0b1 << GPIO_MODER_MODE5_Pos); //Pin 5
    GPIOA->MODER = (GPIOA->MODER &~ GPIO_MODER_MODE6) | ( 0b1 << GPIO_MODER_MODE6_Pos); //Pin 6
    GPIOA->MODER = (GPIOA->MODER &~ GPIO_MODER_MODE7) | ( 0b1 << GPIO_MODER_MODE7_Pos); //Pin 7
    GPIOA->MODER = (GPIOA->MODER &~ GPIO_MODER_MODE15) | ( 0b1 << GPIO_MODER_MODE15_Pos); //Pin 15

    //PORT B
    GPIOB->MODER = (GPIOB->MODER &~ GPIO_MODER_MODE0) | ( 0b1 << GPIO_MODER_MODE0_Pos); //Pin 0
    GPIOB->MODER = (GPIOB->MODER &~ GPIO_MODER_MODE1) | ( 0b1 << GPIO_MODER_MODE1_Pos); //Pin 1
    GPIOB->MODER = (GPIOB->MODER &~ GPIO_MODER_MODE2) | ( 0b1 << GPIO_MODER_MODE2_Pos); //Pin 2

    //PORT C
    GPIOC->MODER = (GPIOC->MODER &~ GPIO_MODER_MODE3) | ( 0b1 << GPIO_MODER_MODE3_Pos); //Pin 3
    GPIOC->MODER = (GPIOC->MODER &~ GPIO_MODER_MODE4) | ( 0b1 << GPIO_MODER_MODE4_Pos); //Pin 4
    GPIOC->MODER = (GPIOC->MODER &~ GPIO_MODER_MODE5) | ( 0b1 << GPIO_MODER_MODE5_Pos); //Pin 5


    // SET GPIO PORT OUTPUT SPEED REGISTER

    //PORT A
    GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR2;
    GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR3;
    GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR4;
    GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR5;
    GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR6;
    GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR7;
    GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR15;

    //PORT B
    GPIOB->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR0;
    GPIOB->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR1;
    GPIOB->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR2;

    //PORT C
    GPIOC->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR3;
    GPIOC->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR4;
    GPIOC->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR5;
    


    //GIVE INITIAL VALUES
    RST(0);
    LAT(1);
    SB(1);
    SCK(0);
    SDA(0);
    ROW0(0);
    ROW1(0);
    ROW2(0);
    ROW3(0);
    ROW4(0);
    ROW5(0);
    ROW6(0);
    ROW7(0);

    /*
    GPIOC->BSRR |= GPIO_BSRR_BR3; //RST set 0
    GPIOC->BSRR |= GPIO_BSRR_BS4; //LAT set 1
    GPIOC->BSRR |= GPIO_BSRR_BS5; //SB set 1
    GPIOB->BSRR |= GPIO_BSRR_BR1; //SCK set 0
    GPIOA->BSRR |= GPIO_BSRR_BR4; //SDA set 0
    GPIOB->BSRR |= GPIO_BSRR_BR2;  //C0 set 0
    GPIOA->BSRR |= GPIO_BSRR_BR15; //C1 set 0
    GPIOA->BSRR |= GPIO_BSRR_BR2;  //C2 set 0
    GPIOA->BSRR |= GPIO_BSRR_BR7;  //C3 set 0
    GPIOA->BSRR |= GPIO_BSRR_BR6;  //C4 set 0
    GPIOA->BSRR |= GPIO_BSRR_BR5;  //C5 set 0
    GPIOB->BSRR |= GPIO_BSRR_BR0;  //C6 set 0
    GPIOA->BSRR |= GPIO_BSRR_BR3;  //C7 set 0
    */

    //Initialize bank 0
    for (int i=0; i<9000000; i++) //wait 100 ms
       asm volatile("nop");   

    RST(1);
    init_bank0();

}





