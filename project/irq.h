#ifndef IRQ_H
#define IRQ_H

#define MAKE_DEFAULT_HANDLER(name_IRQHandler) \
            void __attribute__((weak)) name_IRQHandler (void)\
            {\
                __disable_irq();\
                while (1);\
            }



void irq_init(void);


#endif