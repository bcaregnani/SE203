#ifndef UART_H
#define UART_H

#include<stdint.h>
#include<stddef.h>

extern uint8_t frames[192];

void uart_init(int baudrate);
void uart_putchar(uint8_t c);
uint8_t uart_getchar();
void uart_puts(const char * s);
void uart_gets(char *s, size_t size);
void checksum();
void uart_irq_led_init(void);

#endif