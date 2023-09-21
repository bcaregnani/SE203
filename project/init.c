#include<stdint.h>



extern uint8_t _bvtor, _evtor, _btext, _etext, _brodata, _erodata, _bdata, _edata, _bbss, _ebss;

extern uint8_t _LMAtext, _LMAvtor, _LMAdata;


__attribute__((section(".text_flash"))) void init_text()
{
    uint8_t *src = &_LMAtext;
    uint8_t *dst = &_btext;

    // Copy .text from flash to RAM
    while (dst < &_etext)
        *dst++ = *src++;
    
};





void init ()
{


    uint8_t *src = &_LMAvtor;
    uint8_t *dst = &_bvtor;

    // Copy .vtor from flash to RAM
    while (dst < &_evtor)
            *dst++ = *src++;
    

    src = &_LMAdata;
    dst = &_bdata;
    
    // Copy .data from flash to RAM
    while (dst < &_edata)
        *dst++ = *src++;



    // Zero out bss
    for (dst = &_bbss; dst < &_ebss; dst++)
        *dst = 0;

}