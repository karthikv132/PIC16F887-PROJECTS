/*
 * File:   EEPROM_DATA_WRITE.c
 * Author: Anish D
 *
 * Created on 11 August, 2026, 5:02 PM
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

void delay(int count) 
{
    while (count--);
}

void lcd(int rs, int data) 
{
    RE0 = rs;
    PORTD = data;
    RE1 = 1;
    delay(10);
    RE1 = 0;
    delay(10);
}

void main() 
{
   /* 
    //WRITE DATA TO EEPROM DATA MEMORY MANUALLY
    EEADR = 0X00;// ASSIGN ADDRESS
    EEDAT = 50;// DATA ,WHICH IS TO BE STORE IN ASSIGNED ADDRESS
    EECON1 = 0X06;
    EECON2 = 0X55;
    EECON2 = 0XAA;
    TRISD = 0x00;
    TRISE = 0x00;
    ANSEL = 0x01;
    ANSELH = 0x00;
    lcd(0, 0x38);
    lcd(0, 0x0E);
    while (EEIF == 1);
    EECON1 = 0X02;
    EEADR = 0X00;
    //READ DATA STORED IN EEPROM  MANUALLY
    // EECON1=0X01;
    RD = 1; 
    char data = EEDAT;
    int a = data / 10;
    int b = data % 10;
    lcd(0, 0x80);
    lcd(1, a + 48);
    lcd(1, b + 48);*/
    //USING EEPROM READ WRITE INBUILT FUNCTION
    TRISD = 0x00;
    TRISE = 0x00;
    PORTD=0X00;
    PORTE=0X00;
    ANSEL = 0x00;
    ANSELH = 0x00;
    lcd(0, 0x38);
    lcd(0, 0x0E);
    eeprom_write(2,99);// WRITE FUNCTION (ADDRESS,DATA)
    char value=eeprom_read(2);//READ FUNCTION(ADDRESS)
     int a = value / 10;
    int b = value % 10;
    lcd(0, 0x80);
    lcd(1,a+48);
    lcd(1,b+48);
}