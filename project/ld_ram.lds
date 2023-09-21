MEMORY
    {
        flash (rx) : ORIGIN = 0x08000000, LENGTH = 1M
        sram1 (wx) : ORIGIN = 0x20000000, LENGTH = 96K
        sram2 (wx) : ORIGIN = 0x10000000, LENGTH = 32K
    }


SECTIONS
    {

        .vtor_init :
            {
                *(.vtor_init)
            } > flash

        .vtor :
            {
                _bvtor = . ;
                *(.vtor)
                _evtor = . ;
            } > sram1 AT>flash
        
        .text_flash :
            {
                _btext_flash = . ;
                *(.text_flash)
                _etext_flash = . ;
            } > flash
        
        .text :
            {
                _btext = . ;
                *(.text)
                _etext = . ;
            } > sram1 AT>flash

        .rodata :
		{
                _brodata = . ;
                *(.rodata)
                _erodata = . ;
		} > flash

        .data :
            {
                _bdata = . ;
                *(.data)
                _edata = . ;
            } > sram1 AT>flash
        
        .bss :
            {
                _bbss = . ;
                *(.bss) *(COMMON)
                _ebss = . ;
            } > sram1

    }

_stack = ORIGIN(sram2) + LENGTH(sram2);
_LMAtext = LOADADDR(.text);
_LMAvtor = LOADADDR(.vtor);
_LMAdata = LOADADDR(.data);
ENTRY(_start)