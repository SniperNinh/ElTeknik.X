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

int count = 0;

/*******************************************************************************
* Function: void Init_Timer0()
* Returns: Nothing
* Description: Contains initializations for main
* Usage: initMain()
******************************************************************************/
void Init_Timer0() {
    PSA = 0;    //Prescaler virker med TIMER0
    PS2 = 1;    //Prescaler er sat til 256
    PS1 = 1;
    PS0 = 1;
    TMR0CS = 0; //Intern oscillator
    //OPTION_REG = 0b10000111;      // alle Pull ups er disabled - prescaler er sat til 255 via sidste 3 bits

     GIE = 1;    //Interrupt (GLOBALT) er tændt
     TMR0IE = 1; //Interrupt (TIMER0) er tændt
     TMR0IF = 0; //Interrupt flaget er nulstillet - skal gøres i kode
    //INTCON = 0B11100000;
     
};
/*******************************************************************************
* Function: __interrupt()
*
* Returns: Nothing
*
* Description: Program entry point
******************************************************************************/
void __interrupt() ISR(void)
{
    count++;
        if(count == 100)
    {
        count = 0;
        LATD++;
    }
    TMR0IF = 0;
    TMR0 = 100;
};
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
    Init_Timer0();
    ANSELD = 0;
    TRISD = 0b00000000;
    LATD = 0b00000000;
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
    };
    
    return;
};