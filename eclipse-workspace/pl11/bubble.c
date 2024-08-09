
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000000

void swap(int *element1Ptr, int *element2Ptr)
{
	int hold = *element1Ptr;
	*element1Ptr = *element2Ptr;
	*element2Ptr = hold;
};

int main(void)
{
int* a;
int i = 0;
int j = 0;

unsigned long compCount = 0;
unsigned long swapCount = 0;

a = (int*)malloc(sizeof(int)*N);
srand((int) time(0));
//printf("Random List:\n");
for ( i = 0; i < N; ++i)
	{
		a[i] = rand() % 100;
	//	printf("%d ", a[i]); //prints random numbers
	}
printf("\n\n");
//printf("Ordered List: \n");
 for (i = 0; i < N; ++i) //Loop iterates 100 times
{
	 for ( j = 0; j < N - 1-i; ++j) //function repeats 100 times
	 {
		 compCount++;
		 if (a[j] > a[j + 1])
		 {
		swap(&a[j], &a[j+1]);
		swapCount++;
		 }
	 }
}
/*
 for (i = 0; i < N; ++i) // prints the ordered list
 {
	 printf("%d ", a[i]);
 }
 */
 printf("Number of comparisons: %lu \t", compCount);
 printf("Number of swaps: %lu", swapCount);
printf("\n\n");

free(a);
/*
for (i = 0; i < 100000; ++i)
	{
		a[i] = rand() % 100;

	}
printf("\n\n");

 for (i = 0; i < 100000; ++i) //Loop iterates 100 times
{
	 for (j = 0; j < 100000 - 1; ++j) //function repeats 100 times
	 {
		 if (a[j] > a[j + 1])
		 {
		swap(&a[j], &a[j+1]);
		 }
	 }
}

 for (i = 0; i < N; ++i) // prints the ordered list
 {
	 printf("%d ", a[i]);
 }
*/
return 0;
}

