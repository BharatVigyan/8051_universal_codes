//-----------------------------------------------------------------------------
// Filename: serial.c
// Description: Implementation of serial communication functions for 8051.
//-----------------------------------------------------------------------------
#include <reg51.h>
#include "serial.h"

//-----------------------------------------------------------------------------
// UART Initialization
// Initializes Timer 1 for 9600 baud rate at 12MHz crystal.
//-----------------------------------------------------------------------------
void uart_init() {
    TMOD = 0x20;    // Timer 1, Mode 2 (8-bit auto-reload)
    TH1 = 0xFD;     // Reload value for 9600 baud rate at 12MHz crystal
    SCON = 0x50;    // 8-bit data, 1 stop bit, REN enabled
    TR1 = 1;        // Start Timer 1
}

//-----------------------------------------------------------------------------
// UART Write Byte
// Sends a single byte over the serial port.
//-----------------------------------------------------------------------------
void uart_write(unsigned char dat) {
    SBUF = dat;
    while(TI == 0); // Wait for transmit interrupt flag to be set
    TI = 0;         // Clear the flag
}

//-----------------------------------------------------------------------------
// UART Write String
// Sends a null-terminated string over the serial port.
//-----------------------------------------------------------------------------
void uart_write_string(char *s) {
    while(*s) {
        uart_write(*s++);
    }
}
