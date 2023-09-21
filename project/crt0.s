.syntax unified

.arch armv7-m
.cpu cortex-m4

.global _start
.thumb
.thumb_func //force thumb mode

.section .text_flash, "ax", %progbits

_start:
        ldr r0, =_stack @ end because the stack goes down, symbol in ldscript
        mov sp, r0
        bl init_text
        bl init
        bl main

_exit:
        b _exit
