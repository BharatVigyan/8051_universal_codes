/*
 * File: main.c
 * Description: Main program file that uses the OLED I2C library.
 * This file includes the library header and contains the implementation
 * of the OLED functions as well as the main application logic.
 */
#include <reg51.h>
#include <intrins.h>
#include "oled.h"




// --- Function Prototypes ---
// Declarations for all public functions.
void delay_ms(unsigned int ms);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_Wait_Ack(void);
void I2C_Send_Byte(unsigned char dat);
void OLED_WR_Byte(unsigned char dat, unsigned char cmd);
void OLED_Init(void);
void OLED_CLS(void);
void OLED_Set_Pos(unsigned char x, unsigned char y);
void OLED_ShowChar(unsigned char x, unsigned char y, unsigned char chr);
void OLED_ShowString(unsigned char x, unsigned char y, unsigned char *p);
void OLED_Draw_BMP(unsigned char x0, unsigned char y0, unsigned char x1, unsigned char y1, unsigned char BMP[]);


// --- Main Program ---
void main() {
    delay_ms(100); // Give the OLED time to power up
    OLED_Init();   // Initialize the display
    OLED_CLS();    // Clear the screen

    // Display a message
    OLED_ShowString(0, 0, "Hello!");
    OLED_ShowString(0, 1, "8051 OLED Interface");
    OLED_ShowString(0, 2, "P1.0: SCL");
    OLED_ShowString(0, 3, "P1.1: SDA");
    
    // An infinite loop to keep the program running
    while(1) {
        // You can add more code here to update the display
    }
}
