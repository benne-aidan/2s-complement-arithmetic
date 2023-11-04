/**
 * PLAN:
 * If we just convert binary directly to base-r, we will often get the wrong value,
 * since output has to be in r's complement (11111111 base 2 would be -1 base 10,
 * but should be output as 99999999 (10s complement of 00000001)). We shall take two
 * cases: if binary number is positive, simply convert to base-r as normal. If
 * binary number is negative, perform 2's complement to get regular unsigned value,
 * convert, and then if necessary, perform r's complement.
 * 
 * PSEUDOCODE:
 * if binNum is positive {
 *      toDecimal(binNum);
 *      return;
 * }
 * if binNum is negative {
 *      2sComp(binNum);
 *      toDecimal(binNum);
 *      10sComp(binNum);
 *      return;
 * }
*/

#include <stdio.h>
#include "conversion.h"
#include "complement.h"
#ifndef MAX
#define MAX 8
#endif


void binToDecimal(int a[]) {
    int decimal = 0;

    for (int i = 0; i < MAX; ++i) {
        decimal += a[MAX - i - 1] * power(2, i);
    }

    for (int i = MAX - 1; i >= 0; --i) {
        a[i] = decimal % 10;
        decimal /= 10;
    }
}

void binToOctal(int a[]) {
    int partition1[3] = {0};
    int partition2[3] = {0};
    int partition3[3] = {0};

    // Break binary number into partitions of log_2(8) = 3 digits
    int j = MAX - 1;

    for (int i = 0; i < 3; ++i) {
        partition3[2 - i] = a[j];
        --j;
    }
    for (int i = 0; i < 3; ++i) {
        partition2[2 - i] = a[j];
        --j;
    }
    for (int i = 0; i < 2; ++i) {
        partition1[2 - i] = a[j];
        --j;
    }

    // Convert each partition into an octal digit
    int digit1 = 0;
    for (int i = 0; i < 3; ++i) {
        digit1 += partition1[2 - i] * power(2, i);
    }
    int digit2 = 0;
    for (int i = 0; i < 3; ++i) {
        digit2 += partition2[2 - i] * power(2, i);
    }
    int digit3 = 0;
    for (int i = 0; i < 3; ++i) {
        digit3 += partition3[2 - i] * power(2, i);
    }

    // Combine digits
    for (int i = 0; i < MAX - 3; ++i) {
        a[i] = 0;
    }
    a[MAX - 3] = digit1;
    a[MAX - 2] = digit2;
    a[MAX - 1] = digit3;
}

void binToHexadecimal(int a[]) {
    int partition1[4] = {0};
    int partition2[4] = {0};

    int digit1 = 0;
    int digit2 = 0;

    // Break binary number into partitions of log_2(16) = 4 digits
    int j = MAX - 1;
    for (int i = 0; i < 4; ++i) {
        partition2[3 - i] = a[j];
        --j;
    }
    for (int i = 0; i < 4; ++i) {
        partition1[3 - i] = a[j];
        --j;
    }

    // Convert each partition into a hexadecimal digit
    for (int i = 0; i < 4; ++i) {
        digit1 += partition1[3 - i] * power(2, i);
    }
    for (int i = 0; i < 4; ++i) {
        digit2 += partition2[3 - i] * power(2, i);
    }

    // Store each 'digit' into position in array; each position could have 10, 11, etc, it will be converted later
    for (int i = 0; i < MAX - 2; ++i) {
        a[i] = 0;
    }
    a[MAX - 2] = digit1;
    a[MAX - 1] = digit2;
}

void compToOctal(int a[]) {
    // If a is positive, then just convert to octal and output
    if (a[0] == 0) {
        binToOctal(a);

        // Output result
        for (int i = 0; i < MAX; ++i) {
            printf("%d", a[i]);
        }
    }

    // If a is negative, perform 2s complement, convert to octal, then perform 8s complement
    else if (a[0] == 1) {
        func_2s_comp(a, a);
        binToOctal(a);
        func_8s_comp(a, a);

        // Output result
        for (int i = 0; i < MAX; ++i) {
            printf("%d", a[i]);
        }
    }
    else {
        printf("ERROR: Bad input passed to compToDecimal function\n\n\n");
    }
}

void compToDecimal(int a[]) {
    // If a is positive, just convert to decimal and output
    if (a[0] == 0) {
        binToDecimal(a);
        
        // Output result
        for (int i = 0; i < MAX; ++i) {
            printf("%d", a[i]);
        }
    }

    // If a is negative, perform 2s comp, convert, perform 10s comp
    else if (a[0] == 1) {
        func_2s_comp(a, a);
        binToDecimal(a);
        func_10s_comp(a, a);

        // Output result
        for (int i = 0; i < MAX; ++i) {
            printf("%d", a[i]);
        }
    }
    else {
        printf("ERROR: Bad input passed to compToDecimal function\n\n\n");
    }
}

void compToHexadecimal(int a[]) {
    char hexadecimal[MAX];      // Result array
    
    // If a is positive, just convert to hex and output
    if (a[0] == 0) {
        binToHexadecimal(a);
        for (int i = 0; i < MAX; ++i) {
            hexadecimal[i] = toHexChar(a[i]);
        }

        // Output result
        for (int i = 0; i < MAX; ++i) {
            printf("%c", hexadecimal[i]);
        }
    }

    // If a is negative, perform 2s complement, convert to hexadecimal, then perform 16's complement
    else if (a[0] == 1) {
        // Convert to signed 16s comp
        func_2s_comp(a, a);
        binToHexadecimal(a);
        func_16s_comp(a, a);

        // Convert to characters
        for (int i = 0; i < MAX; ++i) {
            hexadecimal[i] = toHexChar(a[i]);
        }

        // Output result
        for (int i = 0; i < MAX; ++i) {
            printf("%c", hexadecimal[i]);
        }
    }
    else {
        printf("ERROR: Bad input passed to compToDecimal function\n\n\n");
    }
}

char toHexChar(int digit) {
    char hex;
    
    if (digit >= 0 && digit < 10) {
        hex = digit + 48;     // Adjustment to get correct ascii value
    }
    else if (digit >= 10 && digit < 16) {
        hex = digit + 55;     // Adjustment to get correct ascii value
    }
    else {
        printf("ERROR: digit (%d) is not a valid hexadecimal value\n\n\n", digit);
    }

    return hex;
}

int power(int base, int exp) {
    int result = base;
    
    if (base == 0) return 0;
    if (exp == 0) return 1;

    for (int i = 1; i < exp; ++i) {
        result *= base;
    }

    return result;
}