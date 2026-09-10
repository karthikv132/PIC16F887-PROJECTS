/*
 * File:   PRINT_NUM_4_DIGIT.c
 * Author: Anish D
 *
 * Created on 28 July, 2026, 8:36 PM
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

void main(void) 
{
    TRISA=0X00;
    TRISB=0X00;
    TRISC=0X07;
    TRISD=0X00;
    PORTA=0X00;PORTB=0X00;PORTC=0X00;PORTD=0X00;ANSEL=0X00;ANSELH=0X00;
    char seg[10]={0X3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X6F};
    int count=0;
    int a1,a2,a3,a4;int a=0;int i=0;
    while(1)
    {   
        RD0=1;RD1=0;RD2=0;RD3=0;
        if(RC0==1)
        {   
            
           // PORTB=seg[1];
            i=1;
           a=(a%1000)*10+i;            
            while(RC0==1);
        }
        if(RC1==1)
        {
          //  PORTB=seg[2];
              i=2;
           a=(a%1000)*10+i;         
            while(RC1==1);          
        }
        if(RC2==1)
        {
          //  PORTB=seg[3];
            i=3;
           a=(a%1000)*10+i;
            while(RC2==1);
        }
        delay(100);
        RD0=0;RD1=1;RD2=0;RD3=0;
        if(RC0==1)
        {
           // PORTB=seg[4];
            i=4;
          a=(a%1000)*10+i;
            while(RC0==1);
        }
        if(RC1==1)
        {
           // PORTB=seg[5];
            i=5;
           a=(a%1000)*10+i;
            while(RC1==1);
        }
        if(RC2==1)
        {
         //   PORTB=seg[6];
            i=6;
            a=(a%1000)*10+i;
            while(RC2==1);
        }
        delay(100);
        RD0=0;RD1=0;RD2=1;RD3=0;
        if(RC0==1)
        {
           // PORTB=seg[7];
            i=7;
           a=(a%1000)*10+i;
            while(RC0==1);
        }
        if(RC1==1)
        {
           // PORTB=seg[8];
            i=8;
         a=(a%1000)*10+i;
            while(RC1==1);
        }
        if(RC2==1)
        {
           // PORTB=seg[9];
            i=9;
          a=(a%1000)*10+i;
            while(RC2==1);
        }
        delay(100);
        RD0=0;RD1=0;RD2=0;RD3=1;
        if(RC1==1)
        {
          //  PORTB=seg[0];
            i=0;
          a=(a%1000)*10+i;
            while(RC1==1);
        }
        delay(100);
        a1=(a/1000)%10;
        a2=(a/100)%10;
        a3=(a/10)%10;
        a4=(a%10);
        PORTA=0;
        PORTB=seg[a4];
        RA0=1;RA1=0;RA2=0;RA3=0;
        delay(100);
        PORTA=0;
        PORTB=seg[a3];
        RA0=0;RA1=1;RA2=0;RA3=0;
        delay(100);
        PORTA=0;
        PORTB=seg[a2];
        RA0=0;RA1=0;RA2=1;RA3=0;
        delay(100);
        PORTA=0;
        PORTB=seg[a1];
        RA0=0;RA1=0;RA2=0;RA3=1;
        delay(100);
        
    }
}
