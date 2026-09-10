/*
 * File:   TIMER_1.c
 * Author: Anish D
 *
 * Created on 4 August, 2026, 12:01 PM
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
#define _XTAL_FREQ 4000000
int count=0;
void enable() 
{
    RE1 = 1;
    __delay_ms(10);
    RE1 = 0;
    __delay_ms(10);
}

void lcd(char rs, char cmd) {
    RE0 = rs;
    PORTD = cmd;
    enable();
}

void str(char *ptr) {
    while (*ptr != '\0') {
        lcd(1, *ptr++);
    }
}
void tmr()
{
    if(TMR1IF==1)
    {
        count++;
        TMR1IF=0;
        TMR1=3036;
    }
   // lcd(0,0x01);
    if(count<10)
    {
        RA0=1;
        RA1=0;
        RA2=0;
        lcd(0,0x80);
       // __delay_ms(10);
        str("STOP");
       
    }
    if((count>=10)&&(count<16))
    {
        RA0=0;
        RA1=1;
        RA2=0;
        lcd(0,0x80);
        //__delay_ms(10);
        str("GET READY");
    }
    if((count>=16)&&(count<26))
    {
        RA0=0;
        RA1=0;
        RA2=1;
        lcd(0,0x80);
       // __delay_ms(10);
        str("GOOOOO...");
    }
    if(count>26)
    {
        count=0;
        lcd(0,0x01);
    }
}
void main() 
{
    PORTA=0X00;
    TRISA=0X00;
    ANSEL=0X00;
    TRISD = TRISE = 0x00;
    PORTD = PORTE = 0x00;
    ANSEL = 0x00;
    T1CON=0X31;
    TMR1=3036;
    lcd(0, 0x38); //FUNCTION SET - 8 BIT - 2LINE
        
    lcd(0, 0x0C); //DISPLAY ON / CURSOR OFF
        
    lcd(0, 0x80); //FORCE CURSOR TO BEGINNING OF FIRST ROW
       
    while(1)
    {
        tmr();
    }
   
}
