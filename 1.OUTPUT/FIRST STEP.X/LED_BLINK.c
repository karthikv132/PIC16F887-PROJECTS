/*
 * File:   LED_BLINK.c
 * Author: Anish D
 *
 * Created on 22 July, 2026, 4:36 PM
 */


#include <xc.h>
void delay(unsigned int a)
{
    while(a--);
}

void main() 
{
    TRISA=0X00;
    PORTA=0X00;
    ANSEL=0X00;
    while(1)
    {
        PORTA=0X01;
        delay(10000);
        PORTA=0X00;
        delay(10000);
    }
   
}
