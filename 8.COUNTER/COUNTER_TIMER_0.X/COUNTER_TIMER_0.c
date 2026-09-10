/*
 * File:   COUNTER_TIMER_0.c
 * Author: Anish D
 *
 * Created on 5 August, 2026, 9:46 AM
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
    __delay_ms(10); //delay(100);
    RE1 = 0;
    __delay_ms(10); // delay(100);
}

void lcd(char rs, char cmd) 
{
    RE0 = rs;
    PORTD = cmd;
    enable();
}
void main(void) 
{
    TRISA=0X10;
    TRISD=TRISE=PORTD=PORTE=PORTA=ANSEL=ANSELH=0X00;
    OPTION_REG=0XA8;
    TMR0=0;
    lcd(0, 0x38); //FUNCTION SET - 8 BIT - 2LINE
       
    lcd(0, 0x0C); //DISPLAY ON / CURSOR ON
       
    lcd(0, 0x80); //FORCE CURSOR TO BEGINNING OF FIRST ROW
       
    while(1)
    {
        count=TMR0;
        lcd(1,((count/100)%10)+48);
         lcd(1,((count/10)%10)+48);
          lcd(1,((count%10)+48));
        lcd(0,0x80);
    }
}
