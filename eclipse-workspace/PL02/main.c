/*
** Assignment: Laboratory Assignment 02 "Resistor"
**
** Filename: ResistorCode.c
**
** Author: Jaden Ea
** REDID: 130485287
**
** Lab Section: CompE160 laboratory section number 2085
** Lab TA: Shreyas
** Due Date: 9/05/23
**
** Description: This program is to calculate and display the current I in the circuit given input values R1, R2, and R3.
**
**
** Input: None.
**
** Output: The program displays the current I in the circuit and V voltage.
**
** Algorithm: Output a string to stdout (the console) using the standard I/O
printf() function.
**
** Caveats: Describe any known program bugs or limitations.
** Version: 1.0
**
*/

#include <stdio.h>
int main(void)

{

double ohms1;
double ohms2;
double ohms3;
double volts;
double totalResistance;
double amperes;

printf("Enter three resistances in ohms:\n");
scanf("%lf %lf %lf", &ohms1, &ohms2, &ohms3);

totalResistance = 1 / (1/ohms1) + (1/ohms2) + (1/ohms3);

printf("Enter the supply voltage in volts:\n");
scanf("%lf", &volts);

amperes = volts / totalResistance;

printf("the current is %.2lf amperes", amperes);

return(0);

}
