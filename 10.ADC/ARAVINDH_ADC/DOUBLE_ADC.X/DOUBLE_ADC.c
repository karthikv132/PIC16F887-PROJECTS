/*
 * File:   DOUBLE_ADC.c
 * Author: Anish D
 *
 * Created on 10 August, 2026, 10:39 AM
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
int sampling = 0;
int a = 0;
int b = 0;
int c = 0;
int d = 0;
int volt;
int e,f,g,h,v;
int percentage;
int i,j,k;

void delay(int count) {
    while (count--);
}

void lcd(int rs, int data) {
    RE0 = rs;
    PORTD = data;
    RE1 = 1;
    delay(10);
    RE1 = 0;
    delay(10);
}

void pwm(unsigned long int x)
{
    CCPR1L=x>>2;
    DC1B0  = (x >> 0) & 0x01;
    DC1B1  = (x >> 1) & 0x01; 
}
void adc1() {
    GO = 1;
    while (GO == 1);
    sampling = ADRESL + (ADRESH * 256);
    //pwm(sampling);
    a = sampling / 1000;
    b = (sampling % 1000) / 100;
    c = (sampling % 100) / 10;
    d = sampling % 10;
    volt=(sampling*(0.00489))*1000;//0.00489 = 5/1023 that means 5v i/p split into 1023 because it is a 10 bit adc  
    lcd(1, a + 48);
    lcd(1, b + 48);
    lcd(1, c + 48);
    lcd(1, d + 48);
    lcd(1,32);//print space
    
    //lcd(0,0xC0);// 2nd row cursor move comd
    e=volt/1000;
    f=(volt%1000)/100;
    g=(volt%100)/10;
    h=volt%10;
    lcd(1,e+48);
    lcd(1,46);//print .
    lcd(1,f+48);
    lcd(1,g+48);
    lcd(1,h+48);
    lcd(1,86);//print v
    lcd(1,32);//print space
    
    percentage=(sampling*0.098);//100/1023=0.098 
    i=percentage/100;
    j=(percentage%100)/10;
    k=percentage%10;
    lcd(1,i+48);
    lcd(1,j+48);
    lcd(1,k+48);
    lcd(1,37);//print %
    
  
}
void adc2() {
    GO = 1;
    while (GO == 1);
    sampling = ADRESL + (ADRESH * 256);
    pwm(sampling);
    a = sampling / 1000;
    b = (sampling % 1000) / 100;
    c = (sampling % 100) / 10;
    d = sampling % 10;
    volt=(sampling*(0.002445))*1000;//0.00489 = 5/1023 that means 5v i/p split into 1023 because it is a 10 bit adc  
    lcd(0,0xC0);
    lcd(1, a + 48);
    lcd(1, b + 48);
    lcd(1, c + 48);
    lcd(1, d + 48);
     lcd(1,32);
    
    //lcd(0,0xC0);// 2nd row cursor move comd
    e=volt/1000;
    f=(volt%1000)/100;
    g=(volt%100)/10;
    h=volt%10;
    lcd(1,e+48);
    lcd(1,46);//print .
    lcd(1,f+48);
    lcd(1,g+48);
    lcd(1,h+48);
    lcd(1,86);//print v
    lcd(1,32);//print space
    
    percentage=(sampling*0.098);//100/1023=0.098 
    i=percentage/100;
    j=(percentage%100)/10;
    k=percentage%10;
    lcd(1,i+48);
    lcd(1,j+48);
    lcd(1,k+48);
    lcd(1,37);//print %
    
  
}
void main(void) {
     PORTA = PORTD = PORTC = PORTE = 0x00;
    TRISA = 0x0F;
    TRISD = 0x00;
    TRISE = 0x00;
    TRISC = 0X00;
    ANSEL = 0x03;
    ANSELH = 0x00;
    PR2=255;
    T2CON=0X05;
    CCP1CON=0X0C;
    lcd(0, 0x38);
    lcd(0, 0x0C);
    while (1) {
    ADCON0 = 0x81;
    ADCON1 = 0x80;
    lcd(0, 0x80);    
    adc1();
    
    ADCON0 = 0x85;
    ADCON1 = 0xB0;
    lcd(0, 0x80);
    adc2();
    }
    return;
}
