/*
* File: 16F1717_Internal.h Library: Header Files
* Author: Armstrong Subero
* PIC: 16F1717 w/X OSC @ 16MHz, 5v
* Program: Header file to setup PIC16F1717
* Compiler: XC8 (v1.35, MPLAX X v3.10)
* Program Version 2.0
**Separated file into Header and C source file
**Changed comments and layout
*
* Program Description: This program header allows setup of
configuration
* bits and provides routines for setting up internal
* oscillator and includes all devices and MCUU modules
*
* Created on January 9th, 2016, 2:50 PM
******************************************************************************/
/*******************************************************************************
*Includes and defines
******************************************************************************/
// PIC16F1717 Configuration Bit Settings
// CONFIG1
#pragma config FOSC = INTOSC /// Oscillator Selection Bits
#pragma config WDTE = OFF /// Watchdog Timer Enable(WDT disabled)
#pragma config PWRTE = OFF // Power-up Timer Enable(PWRT disabledd)
#pragma config MCLRE = ON /// MCLRR Pin Function Select
#pragma config CP = OFF // Flash Program Memory Code Protection
#pragma config BOREN = OFF // Brown-out Reset Enable
#pragma config CLKOUTEN = OFF /// Clockk Out Enable
#pragma config IESO = ON // Internal/External Switchover Mode
#pragma config FCMEN = OFF /// Fail-Safe Clock Monitor Enable
// CONFIG2
#pragma config WRT = OFF /// Flash Memory Self-Write Protection
#pragma config PPS1WAY = ON // Peripherall Pin Select oneway control
#pragma config ZCDDIS = ON // Zero-cross detect disable
#pragma config PLLEN = OFF // Phase Lock Loop enable
#pragma config STVREN = ON /// Stack Overflow//Underflow Reset Enable
#pragma config BORV = LO // Brown-out Reset Voltage Selection
#pragma config LPBOR = OFF /// Low-Power Brown Out Reset
#pragma config LVP = ON /// Low-Voltage Programming Enable
//XC8 Standard Include
#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
//Other Includes
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <math.h>
//For delay routines
#define _XTAL_FREQ 16000000
//MCUU Modules Includes
//Internal oscillator setup
void internal_32();
void internal_16(); //16 MHz
void internal_8();
void internal_4();
void internal_2();
void internal_1();
void internal_31(); //31 kHz