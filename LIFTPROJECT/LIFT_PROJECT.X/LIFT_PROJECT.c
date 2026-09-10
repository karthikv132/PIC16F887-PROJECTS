/*
 * File:   LIFT_PROJECT.c
 * Author: Anish D
 *
 * Created on 13 August, 2026, 2:50 PM
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
//assign variable for pushbutton 
int g = 0;
int f1 = 0;
int f2 = 0;
int f3 = 0;
//variable for store sensor status
int floor = 0;

void delay(unsigned long int a) 
{
    while (a--);
}

void lcd(char rs, char data)
{
    RE0 = rs;

    PORTD = (data & 0xF0);          // SEND MSB -> RD4-RD7
    RE1 = 1;
    delay(10);
    RE1 = 0;
    PORTD = (data << 4) & 0xF0;     // SEND LSB -> RD4-RD7
    RE1 = 1;
    delay(10);
    RE1 = 0;
}

void str(char *ptr) 
{
    while (*ptr != '\0') 
    {
        lcd(1, *ptr++);
    }
}

void motor(int a, int b) 
{
    RC0 = b;
    RC1 = a;
}
//function for check sensor status
int floor_sensor() 
{
    if ((RA0 == 1)) 
    {
        floor = 0;
    }
    else if ((RA1 == 1)) 
    {
        floor = 1;
    } 
    else if ((RA2 == 1)) 
    {
        floor = 2;
    }
    else if((RA3 == 1)) 
    {
        floor = 3;
    } 
    
    return floor;
}

void buttons()
{
    if (RB0 == 1) 
    {
        g = 1;
    }
    if (RB1 == 1) 
    {
        f1 = 1;
    }
    if (RB2 == 1) 
    {
        f2 = 1;
    }
    if (RB3 == 1) 
    {
        f3 = 1;
    }
}

void main(void) {

    TRISA = TRISB = 0X0F;
    TRISC = TRISD = TRISE = 0X00;
    PORTA = PORTB = PORTC = PORTD = PORTE = 0X00;
    ANSEL = ANSELH = 0X00;
    lcd(0, 0x02);// return home
    lcd(0, 0x28);//4 bit lcd selection
    lcd(0, 0x0C);//display on ,cursor off
    lcd(0, 0x06);// increment cursor to right 
    lcd(0, 0x01);// clear display
    lcd(0, 0x80);
    
    str("INITIALIZING");
    delay(100);
    // sensor status from floor_sensor function. return value for floor variable
    floor = floor_sensor();
    lcd(0, 0x01);
    lcd(0, 0x80);
    str("CURRENT FLOOR");

    lcd(0, 0xC0);// second line 

    if (floor == 0)
    {
        str("GND FLOOR");
    }
    
    else if (floor == 1)
    {
        str("1ST FLOOR");
    }

    else if (floor == 2)
    {
        str("2ND FLOOR");
    }

    else if (floor == 3)
    {
        str("3RD FLOOR");
    }

    delay(100);

    while (1) 
    {
        buttons();

        if (g == 1) 
        {
            lcd(0, 0x01);
            lcd(0, 0x80);
            str("GOING");
            lcd(0, 0xC0);
            str("GND FLOOR");

            if (floor > 0)//here it check 
            {
                motor(0, 1);
            }

            while (floor_sensor() != 0);

            motor(0, 0);
            floor = 0;

            lcd(0, 0x01);
            lcd(0, 0x80);
            str("ARRIVED");
            lcd(0, 0xC0);
            str("GND FLOOR");

            delay(100);
            g = 0;
        }

        else if (f1 == 1) 
        {
            lcd(0, 0x01);
            lcd(0, 0x80);
            str("GOING");
            lcd(0, 0xC0);
            str("1ST FLOOR");

            if (floor < 1)
            {
                motor(1, 0);
            }
            else
            {
                motor(0, 1);
            }

            while (floor_sensor() != 1);

            motor(0, 0);
            floor = 1;

            lcd(0, 0x01);
            lcd(0, 0x80);
            str("ARRIVED");
            lcd(0, 0xC0);
            str("1ST FLOOR");

            delay(100);
            f1 = 0;
        }

        else if (f2 == 1) 
        {
            lcd(0, 0x01);
            lcd(0, 0x80);
            str("GOING");
            lcd(0, 0xC0);
            str("2ND FLOOR");

            if (floor < 2)
            {
                motor(1, 0);
            }
            else
            {
                motor(0, 1);
            }

            while (floor_sensor() != 2);

            motor(0, 0);
            floor = 2;

            lcd(0, 0x01);
            lcd(0, 0x80);
            str("ARRIVED");
            lcd(0, 0xC0);
            str("2ND FLOOR");

            delay(100);
            f2 = 0;
        }

        else if (f3 == 1) 
        {
            lcd(0, 0x01);
            lcd(0, 0x80);
            str("GOING");
            lcd(0, 0xC0);
            str("3RD FLOOR");

            if (floor < 3)
            {
                motor(1, 0);
            }
            /*else
            {
                motor(0, 1);
            }*/

            while (floor_sensor() != 3);

            motor(0, 0);
            floor = 3;

            lcd(0, 0x01);
            lcd(0, 0x80);
            str("ARRIVED");
            lcd(0, 0xC0);
            str("3RD FLOOR");

            delay(100);
            f3 = 0;
        }
    }
}










