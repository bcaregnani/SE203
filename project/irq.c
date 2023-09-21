#include"CMSIS/Device/ST/STM32L4xx/Include/stm32l4xx.h"
#include"CMSIS/Device/ST/STM32L4xx/Include/stm32l475xx.h"
#include"CMSIS/Include/cmsis_gcc.h"
#include"CMSIS/Include/core_cm4.h"
#include"irq.h"
#include<stdio.h>


extern uint8_t _stack;
extern uint8_t _start;



MAKE_DEFAULT_HANDLER(NMI_Handler);
MAKE_DEFAULT_HANDLER(HardFault_Handler);
MAKE_DEFAULT_HANDLER(MemManage_Handler);
MAKE_DEFAULT_HANDLER(BusFault_Handler);
MAKE_DEFAULT_HANDLER(UsageFault_Handler);
MAKE_DEFAULT_HANDLER(SVC_Handler);
MAKE_DEFAULT_HANDLER(PendSV_Handler);
MAKE_DEFAULT_HANDLER(SysTick_Handler);
MAKE_DEFAULT_HANDLER(WWDG_IRQHandler);
MAKE_DEFAULT_HANDLER(PVD_PVM_IRQHa0ndler);
MAKE_DEFAULT_HANDLER(RTC_TAMP_STAMP_IRQHandler);
MAKE_DEFAULT_HANDLER(RTC_WKUP_IRQHandler);
MAKE_DEFAULT_HANDLER(FLASH_IRQHandler);
MAKE_DEFAULT_HANDLER(RCC_IRQHandler);
MAKE_DEFAULT_HANDLER(EXTI0_IRQHandler);
MAKE_DEFAULT_HANDLER(EXTI1_IRQHandler);
MAKE_DEFAULT_HANDLER(EXTI2_IRQHandler);
MAKE_DEFAULT_HANDLER(EXTI3_IRQHandler);
MAKE_DEFAULT_HANDLER(EXTI4_IRQHandler);
MAKE_DEFAULT_HANDLER(DMA1_CH1_IRQHandler);
MAKE_DEFAULT_HANDLER(DMA1_CH2_IRQHandler);
MAKE_DEFAULT_HANDLER(DMA1_CH3_IRQHandler);
MAKE_DEFAULT_HANDLER(DMA1_CH4_IRQHandler);
MAKE_DEFAULT_HANDLER(DMA1_CH5_IRQHandler);
MAKE_DEFAULT_HANDLER(DMA1_CH6_IRQHandler);
MAKE_DEFAULT_HANDLER(DMA1_CH7_IRQHandler);
MAKE_DEFAULT_HANDLER(ADC1_2_IRQHandler);
MAKE_DEFAULT_HANDLER(CAN1_TX_IRQHandler);
MAKE_DEFAULT_HANDLER(CAN1_RX0_IRQHandler);
MAKE_DEFAULT_HANDLER(CAN1_RX1_IRQHandler);
MAKE_DEFAULT_HANDLER(CAN1_SCE_IRQHandler);
MAKE_DEFAULT_HANDLER(EXTI9_5_IRQHandler);
MAKE_DEFAULT_HANDLER(TIM1_BRK_IRQHandler);
MAKE_DEFAULT_HANDLER(TIM1_UP_IRQHandler);
MAKE_DEFAULT_HANDLER(TIM1_TRG_COM_IRQHandler);
MAKE_DEFAULT_HANDLER(TIM1_CC_IRQHandler);
MAKE_DEFAULT_HANDLER(TIM2_IRQHandler);
MAKE_DEFAULT_HANDLER(TIM3_IRQHandler);
MAKE_DEFAULT_HANDLER(TIM4_IRQHandler);
MAKE_DEFAULT_HANDLER(I2C1_EV_IRQHandler);
MAKE_DEFAULT_HANDLER(I2C1_ER_IRQHandler);
MAKE_DEFAULT_HANDLER(I2C2_EV_IRQHandler);
MAKE_DEFAULT_HANDLER(I2C2_ER_IRQHandler);
MAKE_DEFAULT_HANDLER(SPI1_IRQHandler);
MAKE_DEFAULT_HANDLER(SPI2_IRQHandler);
MAKE_DEFAULT_HANDLER(USART1_IRQHandler);
MAKE_DEFAULT_HANDLER(USART2_IRQHandler);
MAKE_DEFAULT_HANDLER(USART3_IRQHandler);
MAKE_DEFAULT_HANDLER(EXTI15_10_IRQHandler);
MAKE_DEFAULT_HANDLER(RTC_ALARM_IRQHandler);
MAKE_DEFAULT_HANDLER(DFSDM1_FLT3_IRQHandler);
MAKE_DEFAULT_HANDLER(TIM8_BRK_IRQHandler);
MAKE_DEFAULT_HANDLER(TIM8_UP_IRQHandler);
MAKE_DEFAULT_HANDLER(TIM8_TRG_COM_IRQHandler);
MAKE_DEFAULT_HANDLER(TIM8_CC_IRQHandler);
MAKE_DEFAULT_HANDLER(ADC3_IRQHandler);
MAKE_DEFAULT_HANDLER(FMC_IRQHandler);
MAKE_DEFAULT_HANDLER(SDMMC1_IRQHandler);
MAKE_DEFAULT_HANDLER(TIM5_IRQHandler);
MAKE_DEFAULT_HANDLER(SPI3_IRQHandler);
MAKE_DEFAULT_HANDLER(UART4_IRQHandler);
MAKE_DEFAULT_HANDLER(UART5_IRQHandler);
MAKE_DEFAULT_HANDLER(TIM6_DACUNDER_IRQHandler);
MAKE_DEFAULT_HANDLER(TIM7_IRQHandler);
MAKE_DEFAULT_HANDLER(DMA2_CH1_IRQHandler);
MAKE_DEFAULT_HANDLER(DMA2_CH2_IRQHandler);
MAKE_DEFAULT_HANDLER(DMA2_CH3_IRQHandler);
MAKE_DEFAULT_HANDLER(DMA2_CH4_IRQHandler);
MAKE_DEFAULT_HANDLER(DMA2_CH5_IRQHandler);
MAKE_DEFAULT_HANDLER(DFSDM1_FLT0_IRQHandler);
MAKE_DEFAULT_HANDLER(DFSDM1_FLT1_IRQHandler);
MAKE_DEFAULT_HANDLER(DFSDM1_FLT2_IRQHandler);
MAKE_DEFAULT_HANDLER(COMP_IRQHandler);
MAKE_DEFAULT_HANDLER(LPTIM1_IRQHandler);
MAKE_DEFAULT_HANDLER(LPTIM2_IRQHandler);
MAKE_DEFAULT_HANDLER(OTG_FS_IRQHandler);
MAKE_DEFAULT_HANDLER(DMA2_CH6_IRQHandler);
MAKE_DEFAULT_HANDLER(DMA2_CH7_IRQHandler);
MAKE_DEFAULT_HANDLER(LPUART1_IRQHandler);
MAKE_DEFAULT_HANDLER(QUADSPI_IRQHandler);
MAKE_DEFAULT_HANDLER(I2C3_EV_IRQHandler);
MAKE_DEFAULT_HANDLER(I2C3_ER_IRQHandler);
MAKE_DEFAULT_HANDLER(SAI1_IRQHandler);
MAKE_DEFAULT_HANDLER(SAI2_IRQHandler);
MAKE_DEFAULT_HANDLER(SWPMI1_IRQHandler);
MAKE_DEFAULT_HANDLER(TSC_IRQHandler);
MAKE_DEFAULT_HANDLER(LCD_IRQHandler);
MAKE_DEFAULT_HANDLER(AES_IRQHandler);
MAKE_DEFAULT_HANDLER(RNG_IRQHandler);
MAKE_DEFAULT_HANDLER(FPU_IRQHandler);


void *vector_table_init[] __attribute__((section(".vtor_init"))) = {
    // Stack and Reset Handler
    &_stack,            /* Top of stack */
    &_start,             /* Reset handler */

    // ARM internal exceptions
    NMI_Handler,        /* NMI handler */
    HardFault_Handler,  /* Hard Fault handler */
    MemManage_Handler,
    BusFault_Handler,
    UsageFault_Handler,
    0,                  /* Reserved */
    0,                  /* Reserved */
    0,                  /* Reserved */
    0,                  /* Reserved */
    SVC_Handler,        /* SVC handler */
    0,                  /* Reserved */
    0,                  /* Reserved */
    PendSV_Handler,     /* Pending SVC handler */
    SysTick_Handler    /* SysTick hanlder */

};


void *vector_table[] __attribute__((section(".vtor"))) = {

    // Stack and Reset Handler
    &_stack,            /* Top of stack */
    &_start,             /* Reset handler */

    // ARM internal exceptions
    NMI_Handler,        /* NMI handler */
    HardFault_Handler,  /* Hard Fault handler */
    MemManage_Handler,
    BusFault_Handler,
    UsageFault_Handler,
    0,                  /* Reserved */
    0,                  /* Reserved */
    0,                  /* Reserved */
    0,                  /* Reserved */
    SVC_Handler,        /* SVC handler */
    0,                  /* Reserved */
    0,                  /* Reserved */
    PendSV_Handler,     /* Pending SVC handler */
    SysTick_Handler,    /* SysTick hanlder */

    // STM32L475 External interrupts

                            /* Position   Description */

    WWDG_IRQHandler,        /* 0 Watchdog IRQ */
    PVD_PVM_IRQHa0ndler,    /* 1  */
    RTC_TAMP_STAMP_IRQHandler,  /* 2 Time Stamp */
    RTC_WKUP_IRQHandler,    /* 3 RTC Wakeup */
    FLASH_IRQHandler,       /* 4 Flash global interrupt */
    RCC_IRQHandler,         /* 5 RCC global interrupt */
    EXTI0_IRQHandler,       /* 6 EXTI Line 0 */
    EXTI1_IRQHandler,       /* 7 EXTI Line 1 */
    EXTI2_IRQHandler,       /* 8 EXTI Line 2 */
    EXTI3_IRQHandler,       /* 9 EXTI Line 3 */
    EXTI4_IRQHandler,       /* 10 EXTI Line 4 */
    DMA1_CH1_IRQHandler,    /* 11 DMA1 Channel 1 */
    DMA1_CH2_IRQHandler,    /* 12 DMA1 Channel 2 */
    DMA1_CH3_IRQHandler,    /* 13DMA1 Channel 3 */
    DMA1_CH4_IRQHandler,    /* 14 DMA1 Channel 4 */
    DMA1_CH5_IRQHandler,    /* 15 DMA1 Channel 5 */
    DMA1_CH6_IRQHandler,    /* 16 DMA1 Channel 6 */
    DMA1_CH7_IRQHandler,    /* 17 DMA1 Channel 7 */
    ADC1_2_IRQHandler,      /* 18 ADC1 and ADC2 global interrupt */
    CAN1_TX_IRQHandler,     /* 19 CAN1_TX interrupt */
    CAN1_RX0_IRQHandler,    /* 20 CAN1_RX0 interrupt */
    CAN1_RX1_IRQHandler,    /* 21 CAN1_RX1 interrupt */
    CAN1_SCE_IRQHandler,    /* 22 CAN1_SCE interrupt */
    EXTI9_5_IRQHandler,     /* 23 EXTI Line[9:5] interrupts */
    TIM1_BRK_IRQHandler,    /* 24 TIM1 Break / TIM15 global interrupts */
    TIM1_UP_IRQHandler,     /* 25 TIM1 Update / TIM16 global interrupts */
    TIM1_TRG_COM_IRQHandler, /*26 TIM1 Trigger and commutation / TIM17 interrupts */
    TIM1_CC_IRQHandler,     /* 27 TIM1 capture compare interrupt */
    TIM2_IRQHandler,        /* 28 TIM2 global interrupt */
    TIM3_IRQHandler,        /* 29 TIM3 global interrupt */
    TIM4_IRQHandler,        /* 30 TIM4 global interrupt */
    I2C1_EV_IRQHandler,     /* 31 I2C1 event interrupt */
    I2C1_ER_IRQHandler,     /* 32 I2C1 event interrupt */
    I2C2_EV_IRQHandler,     /* 33 I2C2 event interrupt */
    I2C2_ER_IRQHandler,     /* 34 I2C2 event interrupt */
    SPI1_IRQHandler,        /* 35 SPI1 global interrupt */
    SPI2_IRQHandler,        /* 36 SPI2 global interrupt */
    USART1_IRQHandler,      /* 37 USART1 global interrupt */
    USART2_IRQHandler,      /* 38 USART2 global interrupt */
    USART3_IRQHandler,      /* 39 USART3 global interrupt */
    EXTI15_10_IRQHandler,   /* 40 EXTI Line[15:10] interrupts */
    RTC_ALARM_IRQHandler,   /* 41 RTC alarms through EXTI line 18 interrupts */
    DFSDM1_FLT3_IRQHandler, /* 42 DFSDM1_FLT3 global interrupt */
    TIM8_BRK_IRQHandler,    /* 43 TIM8 Break interrupt */
    TIM8_UP_IRQHandler,     /* 44 TIM8 Update interrupt */
    TIM8_TRG_COM_IRQHandler,/* 45 TIM8 TRigger and commutation interrupt */
    TIM8_CC_IRQHandler,     /* 46 TIM8 Capture compare interrupt */
    ADC3_IRQHandler,        /* 47 ADC3 global interrupt */
    FMC_IRQHandler,         /* 48 FMC global interrupt */
    SDMMC1_IRQHandler,      /* 49 SDMMC1 global interrupt */
    TIM5_IRQHandler,        /* 50 TIM5 global interrupt */
    SPI3_IRQHandler,        /* 51 SPI3 global interrupt */
    UART4_IRQHandler,       /* 52 UART4 global interrupt */
    UART5_IRQHandler,       /* 53 UART5 global interrupt */
    TIM6_DACUNDER_IRQHandler, /* 54 TIM6 global and DAC1 underrun interrupts */
    TIM7_IRQHandler,        /* 55 TIM7 global interrupt */
    DMA2_CH1_IRQHandler,    /* 56 DMA2 channel 1 interrupt */
    DMA2_CH2_IRQHandler,    /* 57 DMA2 channel 2 interrupt */
    DMA2_CH3_IRQHandler,    /* 58 DMA2 channel 3 interrupt */
    DMA2_CH4_IRQHandler,    /* 59 DMA2 channel 4 interrupt */
    DMA2_CH5_IRQHandler,    /* 60 DMA2 channel 5 interrupt */
    DFSDM1_FLT0_IRQHandler, /* 61 DFSDM1_FLT0 global interrupt */
    DFSDM1_FLT1_IRQHandler, /* 62 DFSDM1_FLT1 global interrupt */
    DFSDM1_FLT2_IRQHandler, /* 63 DFSDM1_FLT2 global interrupt */
    COMP_IRQHandler,        /* 64 COMP1/COMP2 through EXTI lines 21/22 interrupts */
    LPTIM1_IRQHandler,      /* 65 LPTIM1 global interrupt */
    LPTIM2_IRQHandler,      /* 66 LPTIM2 global interrupt */
    OTG_FS_IRQHandler,      /* 67 OTG_FS global interrupt */
    DMA2_CH6_IRQHandler,    /* 68 DMA2 channel 6 interrupt */
    DMA2_CH7_IRQHandler,    /* 69 DMA2 channel 7 interrupt */
    LPUART1_IRQHandler,     /* 70 LPUART1 global interrupt */
    QUADSPI_IRQHandler,     /* 71 QUADSPI global interrupt */
    I2C3_EV_IRQHandler,     /* 72 I2C3 event interrupt */
    I2C3_ER_IRQHandler,     /* 73 I2C3 error interrupt */
    SAI1_IRQHandler,        /* 74 SAI1 global interrupt */
    SAI2_IRQHandler,        /* 75 SAI2 global interrupt */
    SWPMI1_IRQHandler,      /* 76 SWPMI1 global interrupt */
    TSC_IRQHandler,         /* 77 TSC global interrupt */
    LCD_IRQHandler,         /* 78 LCD global interrupt */
    AES_IRQHandler,         /* 79 AES global interrupt */
    RNG_IRQHandler,         /* 80 RNG global interrupt */
    FPU_IRQHandler          /* 81 FLoating point interrupt */
    
};

void irq_init(void)
{
    SCB->VTOR = (uint32_t )vector_table;
}


