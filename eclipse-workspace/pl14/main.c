#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void function(int one) {

	float value;

unsigned short mask = 1<<15;
unsigned short sign = (mask & one) >>15;

unsigned short exponentMask = strtoul("0111110000000000", NULL, 2);
unsigned short exponent = (exponentMask & one) >>10;

unsigned short mantissaMask = strtoul("0000001111111111", NULL, 2);
unsigned short mantissa = (mantissaMask & one);

//case 1
if (exponent == 0) {
	value = pow(-1, sign) * pow(2, -14) * (mantissa / pow(2, 10));
	printf("value = %.15lf", value);
}
//case 3
else if (exponent == 31) {
	if (sign ==0){
		printf("value: +infinity\n");
	}
	else if (sign ==1) {
		printf("value: -infinity\n");
	}
}
//case 2
else {
	value = pow(-1, sign) * pow(2, (exponent - 15)) * (1+ (mantissa / pow(2, 10)));
	printf("value =: %.15lf\n", value);
}

return;
}

int main(int argc, char *argv[]) {

	if (argc > 3) {
		printf("usage: FP16 <msb> <lsb>");
		return 0;
	}

	char bitstring[16];
	strcpy(bitstring, argv[1]);
	strcat(bitstring, argv[2]);
short inputOne = strtoul(bitstring, NULL, 2);

function(inputOne);

return 0;
}
