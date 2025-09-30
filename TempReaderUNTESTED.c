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
ANSELC = 0; //ingen analog på port c
WPUC = 0;
TRISC = 0B00100000;
TRISD = 0B00000000;
PORTD = 0;
ANSELA = 0B00000001;
ADCON0 = 0B00000011;
ADCON1 = 0B11100000;
ADCON2 = 0B00000000;
TRISA = 0B00000001;
};
/*******************************************************************************
* Function: Main
*
* Returns: Nothing
*
* Description: Program entry point
******************************************************************************/
char lADCread = 0B00000000;

void readADC() {
    GO = 1;
    while(GO==1);
    lADCread = ADRESL;
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
    
    while(1) {
        readADC();
        
        PORTD = lADCread;
        __delay_ms(250);
    };
    return;};