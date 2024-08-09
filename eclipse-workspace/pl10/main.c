/*
 * main.c
 *
 *  Created on: Nov 7, 2023
 *      Author: eajad
 */

#include <stdio.h>
#include <string.h>

char* ReverseString(char* stringToReverse) {
   /* TODO: Complete recursive ReverseString() function here. */
	static int low = 0;
	static int high = 0;
	high = strlen(stringToReverse) - 1 - low;

	if (low >= high)
	{
		return stringToReverse;
	}
	else
	{
		char temp;
		temp = stringToReverse[low];
		stringToReverse[low] = stringToReverse[high];
		stringToReverse[high] = temp;
		++low;
		--high;

		stringToReverse = ReverseString(stringToReverse);
	}
	return stringToReverse;
}

int main(void) {
   char inStr[50];
   char* resultStr;

   fgets(inStr, 20, stdin);
   strtok(inStr, "\n");  // Remove newline character from input.
   resultStr = ReverseString(inStr);
   printf("Reversed: %s\n", resultStr);

   return 0;
}
