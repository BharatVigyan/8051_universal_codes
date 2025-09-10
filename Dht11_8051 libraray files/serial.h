//-----------------------------------------------------------------------------
// Filename: serial.h
// Description: Header file for 8051 serial communication functions.
//              Provides prototypes for UART initialization and data transfer.
//-----------------------------------------------------------------------------
#ifndef SERIAL_H
#define SERIAL_H

// Function prototypes for serial communication
void uart_init(void);
void uart_write(unsigned char);
void uart_write_string(char *);

#endif // SERIAL_H
