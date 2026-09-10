/*
 * File:   ARAVINDH_ADC.c
 * Author: Anish D
 *
 * Created on 7 August, 2026, 4:04 PM
 */


#include <xc.h>
int sampling = 0;
int a = 0;
int b = 0;
int c = 0;
int d = 0;
int volt;
int e,f,g,h,v,w;
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


void adc() {
    GO = 1;
    while (GO == 1);
    sampling = ADRESL + (ADRESH * 256);
    a = sampling / 1000;
    b = (sampling % 1000) / 100;
    c = (sampling % 100) / 10;
    d = sampling % 10;
    volt=((sampling*(0.00489))*1000)*4.8;//0.00489 = 5/1023 that means 5v i/p split into 1023 because it is a 10 bit adc  
    lcd(1, a + 48);
    lcd(1, b + 48);
    lcd(1, c + 48);
    lcd(1, d + 48);
    
    
    lcd(0,0xC0);// 2nd row cursor move comd
    e=(volt/10000);
    f=(volt%10000)/1000;
    g=(volt%1000)/100;
    h=(volt%100)/10;
    w=volt%10;
    lcd(1,e+48);
    lcd(1,f+48);
    lcd(1,46);//print .
    lcd(1,g+48);
    lcd(1,h+48);
    lcd(1,w+48);
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
     PORTA = PORTD = PORTE = 0x00;
    TRISA = 0x01;
    TRISD = 0x00;
    TRISE = 0x00;
    ANSEL = 0x01;
    ANSELH = 0x00;
    lcd(0, 0x38);
    lcd(0, 0x0C);
    ADCON0 = 0x81;
    ADCON1 = 0x80;
     while (1) {
        lcd(0, 0x80);
        adc();
    }
    return;
}
