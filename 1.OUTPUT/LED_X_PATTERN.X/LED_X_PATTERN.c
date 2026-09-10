/*
 * File:   LED_X_PATTERN.c
 * Author: Anish D
 *
 * Created on 25 July, 2026, 11:37 AM
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
    int i,a;int count=0;
    TRISA=0X00;
    TRISB=0X00;
    TRISC=0X00;
    TRISD=0X00;
    PORTA=0X00;
    PORTB=0X00;
    PORTC=0X00;
    PORTD=0X00;
    ANSEL=0X00;
    ANSELH=0X00;
    while(1)
    {
        /*PORTA=0X0F;
        delay(100000);
        PORTB=0X0F;
        delay(100000);
        PORTC=0X0F;
        delay(100000);
        PORTD=0X0F;
        delay(100000);
        PORTD=0X00;
        delay(100000);
        PORTC=0X00;
        delay(100000);
        PORTB=0X00;
        delay(100000);
        PORTA=0X00;
        delay(100000);*/
        for(i=0;i<=3;i++)
        {
        PORTA=(1<<i)|a;
        PORTB=(1<<i)|a;
        PORTC=(1<<i)|a;
        PORTD=(1<<i)|a;
        delay(10000);
         a|=1<<count++;
        }
        if(count==3)
        for(i=0;i<=3;i++)
        {
            PORTA = PORTA&(~(1<<i));
            PORTB = PORTB&(~(1<<i));
            PORTC = PORTC&(~(1<<i));
            PORTD = PORTD&(~(1<<i));
            delay(10000);
        }
    }
    
}
