/*
* File: 00-Output Library: Sourse Files
* Author: Armstrong Subero -- Edited Steen Heide
* PIC: 16F1717 --- fosc 16MHz --- Voltage 5v
* Compiler: XC8 v3.0 -- MPLAX 6,25
* Program Version: 1.0
*
* Program Description: Dette program PIC16F1717 sætter en Lysdiode til at lyse PortD Pin0
*
* Hardware Description: An lysdiode er forbundet til RD0 og med en 1K2 modstand till gnd
*/
/*******************************************************************************
*Includes and defines
******************************************************************************/
#include "16F1717_Internal.h"
#include <xc.h>
/*******************************************************************************
* Function: void initMain()
* Returns: Nothing
* Description: Contains initializations for main
* Usage: initMain()
******************************************************************************/
void setup(){
// Run at 16 MHz
internal_16();
// Set PIN D1 as output
TRISB = 0B00000000;
PORTB = 0;
TRISD = 0B00000000;
PORTD = 0;
};
/*******************************************************************************
* Function: Main
*
* Returns: Nothing
*
* Description: Program entry point
******************************************************************************/
void main(void) {
    setup();
    int sek = 0;
    
    int i = 0;
    
    while(1){
        i++;
        if (i > 5) i = 1;
        sek++;
        PORTB = 0b00000001 << i;
        LATD = (char) sek;
        __delay_ms(250);
    };
    return;};