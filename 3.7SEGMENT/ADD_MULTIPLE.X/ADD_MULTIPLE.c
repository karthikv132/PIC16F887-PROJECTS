/*
 * File:   ADD_MULTIPLE.c
 * Author: Anish D
 *
 * Created on 28 July, 2026, 2:12 PM
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

void delay(unsigned long int a) {
    while (a--);
}

void main(void) {
    TRISA = 0X00;
    TRISB = 0X00;
    TRISC = 0X0F;
    PORTA = 0X00;
    PORTB = 0X00;
    PORTC = 0X00;
    ANSEL = 0X00;
    ANSELH = 0X00;
    char seg[10] = {0X3F, 0X06, 0X5B, 0X4F, 0X66, 0X6D, 0X7D, 0X07, 0X7F, 0X6F};
    int count = 0;
    int temp = 0;
    while (1) {
        if (RC0 == 1) {
            count++;
            while (RC0 == 1);
        }
        for (int t = 0; t < 10; t++) {
            RA0 = 0;
            RA1 = 1;
            RA2 = 0;
            RA3 = 0;
            PORTB = seg[count / 10];
            delay(10);
            PORTB = 0;
            RA0 = 1;
            RA1 = 0;
            RA2 = 0;
            RA3 = 0;
            PORTB = seg[count % 10];
            delay(10);
            PORTB = 0;
        }
        if (RC1 == 1) {
            temp++;
            while (RC1 == 1);
        }
        for (int j = 0; j < 10; j++) {
            RA0 = 0;
            RA1 = 0;
            RA2 = 0;
            RA3 = 1;
            PORTB = seg[temp / 10];
            delay(10);
            PORTB = 0;
            RA0 = 0;
            RA1 = 0;
            RA2 = 1;
            RA3 = 0;
            PORTB = seg[temp % 10];
            delay(10);
            PORTB = 0;
        }
        if (RC2 == 1) {
            int add = count + temp;
            while (1) {
                for (int k = 0; k < 100; k++) {
                    RA0 = 0;
                    RA1 = 0;
                    RA2 = 0;
                    RA3 = 1;
                    PORTB = seg[add / 1000];
                    delay(10);
                    PORTB = 0;
                    RA0 = 0;
                    RA1 = 0;
                    RA2 = 1;
                    RA3 = 0;
                    PORTB = seg[(add / 100) % 10];
                    delay(10);
                    PORTB = 0;
                    RA0 = 0;
                    RA1 = 1;
                    RA2 = 0;
                    RA3 = 0;
                    PORTB = seg[(add / 10) % 10];
                    delay(10);
                    PORTB = 0;
                    RA0 = 1;
                    RA1 = 0;
                    RA2 = 0;
                    RA3 = 0;
                    PORTB = seg[add % 10];
                    delay(10);
                    PORTB = 0;
                }

            }
        }
        if (RC3 == 1) {
            int mul = count * temp;
            while (1) {
                for (int k = 0; k < 100; k++) {
                    RA0 = 0;
                    RA1 = 0;
                    RA2 = 0;
                    RA3 = 1;
                    PORTB = seg[mul / 1000];
                    delay(10);
                    PORTB = 0;
                    RA0 = 0;
                    RA1 = 0;
                    RA2 = 1;
                    RA3 = 0;
                    PORTB = seg[(mul / 100) % 10];
                    delay(10);
                    PORTB = 0;
                    RA0 = 0;
                    RA1 = 1;
                    RA2 = 0;
                    RA3 = 0;
                    PORTB = seg[(mul / 10) % 10];
                    delay(10);
                    PORTB = 0;
                    RA0 = 1;
                    RA1 = 0;
                    RA2 = 0;
                    RA3 = 0;
                    PORTB = seg[mul % 10];
                    delay(10);
                    PORTB = 0;
                }

            }
        }

    }

}



