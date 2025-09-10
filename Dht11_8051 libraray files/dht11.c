//-----------------------------------------------------------------------------
// Filename: dht11.c
// Description: Implementation of the DHT11 sensor functions.
//-----------------------------------------------------------------------------
#include <reg51.h>
#include "dht11.h"

// Define DHT11 sensor pin. You can change this to any port/pin.
sbit dht11 = P1^0;

//-----------------------------------------------------------------------------
// Delay Function
// A rough delay loop for 1ms @ 12MHz
//-----------------------------------------------------------------------------
void delay_ms(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++) {
        for (j = 0; j < 120; j++);
    }
}

//-----------------------------------------------------------------------------
// DHT11 Protocol Functions
//-----------------------------------------------------------------------------
bit dht11_start(void) {
    unsigned int timeout_counter = 0;
    dht11 = 0;     // Send start signal: pull bus low for at least 18ms
    delay_ms(20);

    dht11 = 1;     // Pull bus high
    delay_ms(0.00003); // Wait for 30us

    dht11 = 1;     // Set as input
    timeout_counter = 0;
    while (dht11 && timeout_counter < 100) { // Wait for sensor to pull low (20-40us)
        timeout_counter++;
    }
    if(timeout_counter >= 100) return 0; // Timeout, no response

    timeout_counter = 0;
    while (!dht11 && timeout_counter < 100) { // Wait for sensor to pull high (80us)
        timeout_counter++;
    }
    if(timeout_counter >= 100) return 0; // Timeout, no response

    timeout_counter = 0;
    while (dht11 && timeout_counter < 100) { // Wait for sensor to pull low (80us)
        timeout_counter++;
    }
    if(timeout_counter >= 100) return 0; // Timeout, no response
    return 1;
}

unsigned char dht11_read_byte(void) {
    unsigned char i, dat = 0;
    unsigned int timeout_counter = 0;

    for (i = 0; i < 8; i++) { // Read 8 bits
        timeout_counter = 0;
        while (!dht11 && timeout_counter < 100) { // Wait for the start of the bit
            timeout_counter++;
        }
        if(timeout_counter >= 100) return 0; // Timeout

        delay_ms(0.00004); // Wait for 40us to decide if it's a 0 or 1

        if (dht11) { // If still high, it's a '1'
            dat = (dat << 1) | 1;
        } else { // If low, it's a '0'
            dat = (dat << 1) | 0;
        }
        timeout_counter = 0;
        while (dht11 && timeout_counter < 100) { // Wait for the bit to end
            timeout_counter++;
        }
        if(timeout_counter >= 100) return 0; // Timeout
    }
    return dat;
}