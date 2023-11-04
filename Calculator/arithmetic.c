#include <stdio.h>
#include "complement.h"
#ifndef MAX
#define MAX 8
#endif

void func_signed_2s_addition(int a[], int b[], int result[]) {    
    int carry = 0;
    for (int i = MAX - 1; i >= 0; --i) {
        result[i] = (a[i] + b[i] + carry) % 2;
        if (a[i] + b[i] + carry > 1) {
            carry = 1;
        }
        else {
            carry = 0;
        }
    }

    if ((a[0] == 0 && b[0] == 0 && result[0] == 1) || (a[0] == 1 && b[0] == 1 && result[0] == 0)) {
        printf("ERROR: Overflow occurred during signed-2s complement addition.\n");
    }
}

void func_signed_2s_subtraction(int a[], int b[], int result[]) {
    func_2s_comp(b, b);
    func_signed_2s_addition(a, b, result);
}
