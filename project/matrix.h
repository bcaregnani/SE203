#ifndef MATRIX_H
#define MATRIX_H
#include<stdint.h>


typedef struct {
  uint8_t r; //red
  uint8_t g; //green
  uint8_t b; //blue
} rgb_color;

//MACROS FOR CONTROLING PINS

#define RST(x) do{\
            if (x==1)\
                GPIOC->BSRR = (GPIOC->BSRR &~ GPIO_BSRR_BS3_Msk)|((1)<< GPIO_BSRR_BS3_Pos);\
            else if (x==0)\
                GPIOC->BSRR = (GPIOC->BSRR &~ GPIO_BSRR_BR3_Msk)|((1)<< GPIO_BSRR_BR3_Pos);\
                } while(0);
#define SB(x) do{\
            if (x==1)\
                GPIOC->BSRR = (GPIOC->BSRR &~ GPIO_BSRR_BS5_Msk)|((1)<< GPIO_BSRR_BS5_Pos);\
            else if (x==0)\
                GPIOC->BSRR = (GPIOC->BSRR &~ GPIO_BSRR_BR5_Msk)|((1)<< GPIO_BSRR_BR5_Pos);\
                } while(0);
#define LAT(x) do{\
            if (x==1)\
                GPIOC->BSRR = (GPIOC->BSRR &~ GPIO_BSRR_BS4_Msk)|((1)<< GPIO_BSRR_BS4_Pos);\
            else if (x==0)\
                GPIOC->BSRR = (GPIOC->BSRR &~ GPIO_BSRR_BR4_Msk)|((1)<< GPIO_BSRR_BR4_Pos);\
                } while(0);
#define SCK(x) do{\
            if (x==1)\
                GPIOB->BSRR = (GPIOB->BSRR &~ GPIO_BSRR_BS1_Msk)|((1)<< GPIO_BSRR_BS1_Pos);\
            else if (x==0)\
                GPIOB->BSRR = (GPIOB->BSRR &~ GPIO_BSRR_BR1_Msk)|((1)<< GPIO_BSRR_BR1_Pos);\
                } while(0);
#define SDA(x) do{\
            if (x==1)\
                GPIOA->BSRR = (GPIOA->BSRR &~ GPIO_BSRR_BS4_Msk)|((1)<< GPIO_BSRR_BS4_Pos);\
            else if (x==0)\
                GPIOA->BSRR = (GPIOA->BSRR &~ GPIO_BSRR_BR4_Msk)|((1)<< GPIO_BSRR_BR4_Pos);\
                } while(0);
#define ROW0(x) do{\
            if (x==1)\
                GPIOB->BSRR = (GPIOB->BSRR &~ GPIO_BSRR_BS2_Msk)|((1)<< GPIO_BSRR_BS2_Pos);\
            else if (x==0)\
                GPIOB->BSRR = (GPIOB->BSRR &~ GPIO_BSRR_BR2_Msk)|((1)<< GPIO_BSRR_BR2_Pos);\
                } while(0);    //C0
#define ROW1(x) do{\
            if (x==1)\
                GPIOA->BSRR = (GPIOA->BSRR &~ GPIO_BSRR_BS15_Msk)|((1)<< GPIO_BSRR_BS15_Pos);\
            else if (x==0)\
                GPIOA->BSRR = (GPIOA->BSRR &~ GPIO_BSRR_BR15_Msk)|((1)<< GPIO_BSRR_BR15_Pos);\
                } while(0);    //C1
#define ROW2(x) do{\
    if(x==1)\
        (GPIOA->BSRR = (GPIOA->BSRR &~ GPIO_BSRR_BS2_Msk)| ((1)<< GPIO_BSRR_BS2_Pos));\
    else\
        (GPIOA->BSRR = (GPIOA->BSRR &~ GPIO_BSRR_BR2_Msk)| ((1)<< GPIO_BSRR_BR2_Pos));\
}while(0);   //C2
#define ROW3(x) do{\
    if(x==1)\
        (GPIOA->BSRR = (GPIOA ->BSRR &~ GPIO_BSRR_BS7_Msk)| ((1)<< GPIO_BSRR_BS7_Pos));\
    else if(x==0)\
        (GPIOA->BSRR = (GPIOA->BSRR &~ GPIO_BSRR_BR7_Msk)| ((1)<< GPIO_BSRR_BR7_Pos));\
}while(0);        //C3
#define ROW4(x) do{\
    if(x==1)\
        (GPIOA->BSRR = (GPIOA->BSRR &~ GPIO_BSRR_BS6_Msk)| ((1)<< GPIO_BSRR_BS6_Pos));\
    else if(x==0)\
        (GPIOA->BSRR = (GPIOA->BSRR &~ GPIO_BSRR_BR6_Msk)| ((1)<< GPIO_BSRR_BR6_Pos));\
}while(0);      //C4
#define ROW5(x) do{\
    if(x==1)\
        (GPIOA->BSRR = (GPIOA->BSRR &~ GPIO_BSRR_BS5_Msk)| ((1)<< GPIO_BSRR_BS5_Pos));\
    else if(x==0)\
        (GPIOA->BSRR = (GPIOA->BSRR &~ GPIO_BSRR_BR5_Msk)| ((1)<< GPIO_BSRR_BR5_Pos));\
}while(0);     //C5
#define ROW6(x) do{\
    if(x==1)\
        (GPIOB->BSRR = (GPIOB ->BSRR &~ GPIO_BSRR_BS0_Msk)| ((1)<< GPIO_BSRR_BS0_Pos));\
    else if(x==0)\
        (GPIOB->BSRR = (GPIOB ->BSRR &~ GPIO_BSRR_BR0_Msk)| ((1)<< GPIO_BSRR_BR0_Pos));\
}while(0);     //C6
#define ROW7(x) do{\
    if(x==1)\
        (GPIOA->BSRR = (GPIOA->BSRR &~ GPIO_BSRR_BS3_Msk)| ((1)<< GPIO_BSRR_BS3_Pos));\
    else if(x==0)\
        (GPIOA->BSRR = (GPIOA->BSRR &~ GPIO_BSRR_BR3_Msk)| ((1)<< GPIO_BSRR_BR3_Pos));\
}while(0);      //C7



//GENERATION OF PULSES

#define pulse_SCK do{\
SCK(0);\
asm volatile("nop");\
asm volatile("nop");\
SCK(1);\
asm volatile("nop");\
asm volatile("nop");\
SCK(0);\
asm volatile("nop");\
asm volatile("nop");\
}while(0);    //Generate a positive pulse in SCK
#define pulse_LAT do{\
LAT(1);\
asm volatile("nop");\
asm volatile("nop");\
LAT(0);\
asm volatile("nop");\
asm volatile("nop");\
LAT(1);\
asm volatile("nop");\
asm volatile("nop");\
}while(0);     //Generate a negative pulse in LAT



void deactivate_rows();
void activate_row(uint8_t row);
void send_byte(uint8_t val, uint8_t bank);
void mat_set_row(int row, const rgb_color *val);
void init_bank0();
void test_pixels();
void show_image();
void matrix_init();



#endif