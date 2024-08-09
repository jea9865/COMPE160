/*
** Assignment: Laboratory Assignment 09 "Resistor"
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
	int i = 0;
	double sample[579];
	double average;
	double sum;

	FILE *fPtr;
     // fopen opens file; exits program if file cannot be opened
     if ((fPtr = fopen("Debug/signal.dat", "r")) == NULL) {
           puts("File could not be opened\n");
     }
     else {

           // while not end of file
           while (!feof(fPtr)) {
                fscanf(fPtr, "%lf", &sample[i]);
                ++i;
                printf("%7.3f\n", sample[i]);

           }
           fclose(fPtr); // fclose closes the file
     }

	FILE* outFile10 = NULL;
	outFile10 = fopen("signal10.dat", "w");
	if (outFile10 == NULL) {
		puts("Could not open file signal.out\n");
	}
	else
	{
		//implement a for loop to print the averages into the signal.out file.
		for (i = 0; i < 579; ++i)
		{
			sum = 0;
			for (int j = i; j < i + 10; ++j)
			{
			sum += sample[j];
			}
			average = sum / (10 + 1);
			fprintf(outFile10, "%lf\n", average);
		}
		fclose(outFile10);
	}

	FILE* outFile100 = NULL;
		outFile100 = fopen("signal100.dat", "w");
		if (outFile100 == NULL) {
			puts("Could not open file signal.out\n");
		}
		else
		{
			//implement a for loop to print the averages into the signal.out file.
			for (i = 0; i < 579; ++i)
			{
				sum = 0;
				for (int j = i; j < i + 100; ++j)
				{
				sum += sample[j];
				}
				average = sum / (100 + 1);
				fprintf(outFile10, "%lf\n", average);
			}
			fclose(outFile10);
		}
}

