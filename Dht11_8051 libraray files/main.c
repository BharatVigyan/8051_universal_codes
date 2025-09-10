//-----------------------------------------------------------------------------
// Filename: main.c
// Description: Main source file for DHT11 sensor interface on 8051.
//              Contains the main program loop.
//-----------------------------------------------------------------------------

#include <reg51.h>    // Include 8051 register definitions here
#include "dht11.h"    // Include our custom header file for DHT11
#include "serial.h"   // Correctly include the serial header file

// Global variables (defined here, declared as extern in the header)
unsigned char dht11_data[5];
unsigned char humidity_integral, humidity_decimal, temperature_integral, temperature_decimal, checksum;

//-----------------------------------------------------------------------------
// Main Function
//-----------------------------------------------------------------------------
void main() {
    uart_init(); // Initialize the UART

    while (1) {
        // Read data from DHT11 sensor
        if (dht11_start()) { // Check for sensor response
            dht11_data[0] = dht11_read_byte(); // Humidity integer
            dht11_data[1] = dht11_read_byte(); // Humidity decimal
            dht11_data[2] = dht11_read_byte(); // Temperature integer
            dht11_data[3] = dht11_read_byte(); // Temperature decimal
            dht11_data[4] = dht11_read_byte(); // Checksum

            // Calculate checksum and verify data integrity
            checksum = dht11_data[0] + dht11_data[1] + dht11_data[2] + dht11_data[3];

            if (dht11_data[4] == checksum) {
                // Data is valid. Store in global variables.
                humidity_integral = dht11_data[0];
                temperature_integral = dht11_data[2];

                // Send the data over UART
                uart_write_string("Humidity: ");
                uart_write(humidity_integral / 10 + '0');
                uart_write(humidity_integral % 10 + '0');
                uart_write_string("% | Temperature: ");
                uart_write(temperature_integral / 10 + '0');
                uart_write(temperature_integral % 10 + '0');
                uart_write_string(" C\r\n");
            } else {
                uart_write_string("Checksum Error!\r\n");
            }
        } else {
            uart_write_string("DHT11 not responding!\r\n");
        }

        delay_ms(2000); // Wait for 2 seconds before next reading
    }
}
