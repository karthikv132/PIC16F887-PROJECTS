/*
 * File:   PRINT_LCD.c
 * Author: Anish D
 *
 * Created on 29 July, 2026, 4:21 PM
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
void delay(unsigned long int a)
{
    while(a--);
}
void enable()
{
    RE1=1;
    delay(100);
    RE1=0;
    delay(100);
}
void lcd(char rs,char cmd)
{
    RE0=rs;
    PORTD=cmd;
    enable();
}

void main(void) 
{
    TRISD=TRISE=0X00;
    PORTD=PORTE=0X00;
    ANSEL=ANSELH=0X00;
    lcd(0,0X38);
    lcd(0,0X0E);
    lcd(0,0X80);
    while(1)
    {
        lcd(1,'K');
        
        lcd(1,'A');
        
        lcd(1,'R');
        
        lcd(1,'T');
        
        lcd(1,'H');
        
        lcd(1,'I');
       
        lcd(1,'K');
        while(1);
       
    }
    
}
