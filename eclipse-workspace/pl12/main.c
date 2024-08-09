#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double rectangle_method(double a, double b, int N){
	double deltaX = (b - a) / N;
	double totalArea = 0;
	double area = 0;

	for (int i = 0; i < N; ++i) {
		area = (1 / (((a + deltaX * i) + (a + deltaX * (i + 1))) / 2)) * deltaX;
		totalArea += area;
	}
	return totalArea;
}

double trapezoid_method(double a, double b, int N) {
	double deltaX = (b - a) / N;
	double totalArea = 0;
	double area = 0;

	for (int i = 0; i < N; ++i) {
		area = (deltaX / 2) * (1/(a + deltaX * i) + 1/(a + deltaX * (i+1)));
		totalArea += area;
	}
	return totalArea;
}



int main(int argc, char* argv[])
{
	long unsigned int N = 10;
	double a = atof(argv[1]);
	double b = atof(argv[2]);
	double real = atof(argv[3]);

	for (int i = 0; i < 9; ++i) {
		double area = rectangle_method(a, b, N);

			double rectError = fabs(real - area);
			printf("rect: n = % 11ld, area = %lf, err = %.13e\n", N, area, rectError);

		double trapArea = trapezoid_method(a, b, N);

		double trapError = fabs(real - trapArea);
		printf("Trap: n = % 11ld, area = %lf, err = %.13e\n", N, trapArea, trapError);

		N = N * 10;
	}



return 0;
}
