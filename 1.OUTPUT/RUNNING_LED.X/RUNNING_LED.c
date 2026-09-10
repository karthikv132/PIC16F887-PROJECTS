/*
 * File:   RUNNING_LED.c
 * Author: Anish D
 *
 * Created on 23 July, 2026, 11:40 AM
 */
// PIC16F887 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = ON        // Internal External Switchover bit (Internal/External Switchover mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is enabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
void delay(unsigned int a)
{
    while(a--);
}

void main(void) 
{
    unsigned int i;
    TRISA=0X00;
    PORTA=0X00;
    ANSEL=0X00;
    while(1)
    {
    for(i=0;i<8;i++)
        {
            PORTA=(1<<i);
            delay(10000);   
        }
    }
}
/* PORTA=0X01;
        delay(10000);
        PORTA=0X00;
        delay(10000);
        PORTA=0X02;
        delay(10000);
        PORTA=0X00;
        delay(10000);
        PORTA=0X04;
        delay(10000);
        PORTA=0X00;
        delay(10000);
        PORTA=0X08;
        delay(10000);
        PORTA=0X00;
        delay(10000);
        PORTA=0X10;
        delay(10000);
        PORTA=0X00;
        delay(10000);
        PORTA=0X20;
        delay(10000);
        PORTA=0X00;
        delay(10000);
        PORTA=0X40;
        delay(10000);
        PORTA=0X00;
        delay(10000);
        PORTA=0X80;
        delay(10000);
        PORTA=0X00;
        delay(10000);*/