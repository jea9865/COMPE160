#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

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

double rectangle_method_omp(double a, double b, int N){
	double deltaX = (b - a) / N;
	double totalArea = 0;
	double area = 0;
	int numThreads = 1;

/*
	for (int i = 0; i < N; ++i) {
		area = (1 / (((a + deltaX * i) + (a + deltaX * (i + 1))) / 2)) * deltaX;
		totalArea += area;
	}
	*/

#pragma omp parallel
        {
                numThreads = omp_get_num_threads();
        }

        double* s = (double*)calloc(numThreads, sizeof(double));

#pragma omp parallel
        {
                int id = omp_get_thread_num();
                int istart = id * N / numThreads;
                int iend = (id + 1) * N / numThreads;

                for (size_t i = istart; i<iend; i++)
                {

                    area = (1 / (((a + deltaX * i) + (a + deltaX * (i + 1))) / 2)) * deltaX;

                    s[id] += area;
                }
        }
                for (int i = 0; i < numThreads; ++i) {
                	totalArea += s[i];
                }

        return totalArea;
}

int main(int argc, char* argv[])
{
	clock_t begin, end;
	int numThreads = 1;
	#pragma omp parallel
	        {
	                numThreads = omp_get_num_threads();
	        }
    omp_set_dynamic(0); // disables dynamic adjustment of the number of threads
	omp_set_num_threads(numThreads);


	double a = atof(argv[1]);
	double b = atof(argv[2]);
	double real = atof(argv[3]);

	for(int n = 1e1 * numThreads; n <= 1e7 * numThreads; n *= 10) {
		begin = clock();
			double area = rectangle_method(a, b, n);
			end = clock();
				double rectError = fabs(real - area);
				printf("rect: n = % 11d, area = %lf, err = %.13e\n", n, area, rectError);
			printf("Elapsed time = %.2e s (serial)\n\n", (((double)(end - begin))/CLOCKS_PER_SEC));

			begin = clock();
			area = rectangle_method_omp(a, b, n);
			end = clock();
			rectError = fabs(real - area);
			printf("rect: n = % 11d, area = %lf, err = %.13e\n", n, area, rectError);
			printf("Elapsed time = %.2e s (parallel)\n\n", (((double)(end - begin))/CLOCKS_PER_SEC));

	}

return 0;
}
