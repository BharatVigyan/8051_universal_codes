//-----------------------------------------------------------------------------
// Filename: dht11.h
// Description: Header file for DHT11 sensor interface on 8051 microcontroller.
//              Contains function prototypes and external variable declarations.
//-----------------------------------------------------------------------------
#ifndef DHT11_H
#define DHT11_H

// Function prototypes
void delay_ms(unsigned int);
unsigned char dht11_read_byte(void);
bit dht11_start(void);

// Global variables to store the data read from the sensor
extern unsigned char dht11_data[5];
extern unsigned char humidity_integral, humidity_decimal, temperature_integral, temperature_decimal, checksum;

#endif // DHT11_H
