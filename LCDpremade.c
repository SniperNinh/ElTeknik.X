/*File: 39-LCD-elev-fil.c        Library: Sourse Files
* Author:  Steen Heide
* PIC: 16F1717 --- fosc 16MHz --- Voltage 5v
* Compiler: XC8 v3.0 -- MPLAX 6,25
* Program Version: 1.0
*
* Program Description: Dette program sætter udskriver på et LCD
* display dels som enkelt tegn, dels som tal og dels som flere tegn i form af en streng
* Hardware Description: An lysdiode er forbundet til RD0 og med en 1K2 modstand til gnd     */
/*******************************************************************************
*Includes and defines
******************************************************************************/
#include "16F1717_Internal.h"
#include <xc.h>
#define _XTAL_FREQ 16000000

#define RS      RE0
#define EN      RE2
#define D4      RA6
#define D5      RC0
#define D6      RC1
#define D7      RC3

#define S1      RC5
#define S2      RC4

#include "Display_lib.h"

char lADCread = 0B00000000;

void readADC() {
    GO = 1;
    while(GO==1);
    lADCread = ADRESL;
};

/*******************************************************************************
* Function: void setup()
******************************************************************************/
void setup (){
    OSCCON = 0b01101000;  		// Sætter fosc = 16 MHz
    
    WPUA = 0;
    ANSELA = 0B00000001;         //   ANSEL0 = adc0 0 an0
    TRISA = 0B00000001;        //   Specielt RA6 sættes som udgang  D4 LCD
    
    ADCON0 = 0B00000011;
    ADCON1 = 0B11100000;
    ADCON2 = 0B00000000;
    
    WPUC = 0;
    ANSELC = 0B00000000;    
    TRISC = 0B00000000;        // Specielt RC0 RC1 RC2 sættes som udgang  C5, C6,C7
    
    WPUD = 0;
    ANSELD = 0B00000000;    
    TRISD = 0B00000000;        // Specielt RC0 RC1 RC2 sættes som udgang  C5, C6,C7
    
    WPUE = 0;
    ANSELE = 0;
    TRISE = 0B00000000;        // Specielt RE0 RE2 sættes som udgang  RS og EN
    
    }
/*******************************************************************************
* Function: Get Adc value
******************************************************************************/
void Lcd_Print_Int(unsigned int value) {
    char buffer[6];
    int j = 0;
    int i = 0;
    while (value > 0) {
        buffer[i++] = (value % 10 + '0');
        j++;
        value /= 10;
    };
    Lcd_Set_Cursor(1,1);
    while(j>0) {
        if (j == 1) {
            Lcd_Print_Char(0x2c);
        };
        Lcd_Print_Char(buffer[--i]);
        j--;
    };
    Lcd_Print_Char(0xdf);
};
void main(void)  {
    setup();
    Lcd_Start();                // slutter LCD display op
    Lcd_Clear();
    
    Lcd_Set_Cursor(2,1);
    Lcd_Print_String("Mathias er gay");
    
    unsigned int heat;
    
// /*  test 1 skriv eget navn, og sæt det på anden linje fjerde plads
    
// */
    while(1){
        readADC();
        PORTD = lADCread;
        
        heat = (unsigned int) ((int) lADCread*5);
        
        Lcd_Print_Int(heat);
        
        __delay_ms(250);
    }
}
