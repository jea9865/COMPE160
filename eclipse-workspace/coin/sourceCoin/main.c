/*
** Assignment: Laboratory Assignment 07 "Coin Flip"
**
** Filename: ResistorCode.c
**
** Author: Jaden Ea
** REDID: 130485287
**
** Lab Section: CompE160 laboratory section number 2085
** Lab TA: Shreyas
** Due Date: 10/12/23
**
** Description: This program is to calculate and display the current I in the circuit given input values R1, R2, and R3.
**
**
** Input: None.
**
** Output: The program displays the number of flips needed to aquire desired number of heads.
**
** Algorithm: Output a string to stdout (the console) using the standard I/O
printf() function.
**
** Caveats: Describe any known program bugs or limitations.
** Version: 1.0
**
*/

#include <stdio.h>
#include "../headers/Coin.h"
//int CountHeads(Coin coin, int goal) {
//int i;
//
//	for(i =0; i < goal *100; ++i)
//	{
//	     if (coin.heads < goal) {
//	    	 coin = Flip(coin);
//	     }
//	     else {
//	    	 break;
//	     }
//	}
//	return NumFlips(coin);
//}
int CountHeads(Coin coin, int goal) {
	while( NumHeads(coin) < goal){
	    	 coin = Flip(coin);
	}
	return NumFlips(coin);
}
// This function creates a coin object and calls the method for testing
int main() {
Coin coin = InitCoin(15); // Create a coin object with seed value 15
int numHeads = 20; // Desire 20 heads
int numFlips = CountHeads(coin, numHeads); // Should return 40 using coinobject with seed value 15
printf("Total number of flips for 20 heads: %d\n", numFlips);
coin = InitCoin(15);
numHeads = 100; // Desire 100 heads
numFlips = CountHeads(coin, numHeads); // Should return 194 using coin objectwith seed value 15
printf("Total number of flips for 100 heads: %d\n", numFlips);
return 0;
}
