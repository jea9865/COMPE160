#include <stdio.h>
#include <stdlib.h>

int countSetBits(unsigned int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

void printBinaryString(unsigned int num) {
    for (int i = 31; i >= 0; --i) {
        putchar((num & (1u << i)) ? '1' : '0');
        if (i % 8 == 0) putchar(' ');
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <binary_string1> <binary_string2>\n", argv[0]);
        return 1;
    }

    unsigned int num1 = strtol(argv[1], NULL, 2);
    unsigned int num2 = strtol(argv[2], NULL, 2);

    unsigned int resultAND = num1 & num2;
    unsigned int resultOR = num1 | num2;
    unsigned int resultXOR = num1 ^ num2;

    printf("AND: ");
    printBinaryString(resultAND);
    printf("(%d)\n", countSetBits(resultAND));

    printf("OR : ");
    printBinaryString(resultOR);
    printf("(%d)\n", countSetBits(resultOR));

    printf("XOR: ");
    printBinaryString(resultXOR);
    printf("(%d)\n", countSetBits(resultXOR));

    return 0;
}
