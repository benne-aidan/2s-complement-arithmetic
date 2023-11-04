#include <stdio.h>
#include "arithmetic.h"
#include "conversion.h"
#ifndef MAX
#define MAX 8
#endif

void takeInput(int x[], int y[]);
void baseMenu(int a[]);

int main(void) {
	int x[MAX];
	int y[MAX];

	int menuChoice = -1;

	while (menuChoice != 0) {
        int result[MAX] = {0};
		setbuf(stdout, NULL);
		printf("Enter the command number:\n\t0) Exit\n\t1) Addition in signed-2s-complement\n\t2) Subtraction in signed-2s-complement\n");

		// Check if input is int
		// Check for valid int range is accomplished in switch statement default branch
		if (scanf("%d", &menuChoice) != 1) {
			printf("Input should be an integer.\n");
			while ((getchar()) != '\n');
			continue;
		}
		
		// Handle user input
		switch(menuChoice) {
			case 0:                 // Exit
				break;
			case 1:
				takeInput(x, y);
				func_signed_2s_addition(x, y, result);
				baseMenu(result);
				break;
			case 2:
				takeInput(x, y);
				func_signed_2s_subtraction(x, y, result);
				baseMenu(result);
				break;
			default:
				// If user inputted wrong command number
				printf("%d is not a valid command.\n", menuChoice);
				break;
		}
	}
	return 0;
}

void takeInput(int x[], int y[]) {
    printf("Enter first binary number:\n");
    for (int i = 0; i < MAX; ++i) {
        printf("x%d = ", i);
        while ((scanf("%d", &x[i]) != 1) || (x[i] != 0 && x[i] != 1)) {
            printf("Input can only be 0 or 1.\nx%d = ", i);
            while (getchar() != '\n');
        }
    }

    printf("Enter the second binary number:\n");
    for (int i = 0; i < MAX; ++i) {
        printf("y%d = ", i);
        while ((scanf("%d", &y[i]) != 1) || (y[i] != 0 && y[i] != 1)) {
            printf("Input can only be 0 or 1.\nx%d = ", i);
            while (getchar() != '\n');
        }
    }
}

void baseMenu(int a[]) {
	int flag = 0;
	int menuChoice;

	while (!flag) {
		printf("Enter the output base:\n1) Binary\n2) Octal\n3) Decimal\n4) Hexadecimal\n");

		if (scanf("%d", &menuChoice) != 1) {
			printf("Input should be an integer.\n");
			while ((getchar()) != '\n');
			continue;
		}

		switch(menuChoice) {
			case 1:
				printf("Result in binary: ");
				for (int i = 0; i < MAX; ++i) {
					printf("%d", a[i]);
				}
				printf("\n");
				flag = 1;
				break;
			case 2:
				printf("Result in octal: ");
				compToOctal(a);
				printf("\n");
				flag = 1;
				break;
			case 3:
				printf("Result in decimal: ");
				compToDecimal(a);
				printf("\n");
				flag = 1;
				break;
			case 4:
				printf("Result in hexadecimal: ");
				compToHexadecimal(a);
				printf("\n");
				flag = 1;
				break;
			default:
				printf("%d is not a valid command.\n", menuChoice);
				break;
		}
	}
}
