/*
 * main.c
 *
 *  Created on: Oct 10, 2023
 *      Author: eajad
 */

#include <stdio.h>
#include "Coin.h"

int CountHeads(Coin coin, int goal) {
	int flips = 0;

	while (coin.heads < goal)
	{
	    ++flips;
	}
	return flips;
}

// This function creates a coin object and calls the method for testing
int main()
{
Coin coin = InitCoin(15); // Create a coin object with seed value 15
int numHeads = 20; // Desire 20 heads
int numFlips = CountHeads(coin, numHeads); // Should return 40 using coin object with seed value 15
printf("Total number of flips for 20 heads: %d\n", numFlips);
coin = InitCoin(15);
numHeads = 100; // Desire 100 heads
numFlips = CountHeads(coin, numHeads); // Should return 194 using coin object with seed value 15
printf("Total number of flips for 100 heads: %d\n", numFlips);
return 0;
}

