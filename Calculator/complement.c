#ifndef MAX
#define MAX 8
#endif

void func_1s_comp(int a[], int result[]) {
	for (int i = 0; i < MAX; ++i) {
		result[i] = !(a[i]);
	}
}

void func_2s_comp(int a[], int result[]) {
	int found1 = 0;

	for (int i = MAX - 1; i >= 0; --i) {
		if (found1) {
			result[i] = !(a[i]);
		}
		else {
			result[i] = a[i];
			if (a[i] == 1) found1 = 1;
		}
	}
}

// Each of the following functions use a nearly identical algorithm: could likely create general function for r's complement

void func_7s_comp(int a[], int result[]) {
	// 77777777 - aaaaaaaa
	for (int i = MAX - 1; i >= 0; --i) {
		// No need to account for borrow because all octal digits are <= 7
		result[i] = 7 - a[i];
	}
}

void func_8s_comp(int a[], int result[]) {
	// Perform 7s comp and increment
	func_7s_comp(a, result);

	for (int i = MAX - 1; i >= 0; --i) {
		if (result[i] + 1 > 7) {
			result[i] = 0;
		}
		else {
			result[i] += 1;
			break;
		}
	}
}

void func_9s_comp(int a[], int result[]) {
	// 99999999 - aaaaaaaa	
	for (int i = MAX - 1; i >= 0; --i) {
		// No need to account for borrow because all decimal digits are <= 9
		result[i] = 9 - a[i];
    }
}

void func_10s_comp(int a[], int result[]) {
	// Perform 9s comp and increment
	func_9s_comp(a, result);

	for (int i = MAX - 1; i >= 0; --i) {
		if (result[i] + 1 > 9) {
			result[i] = 0;
		}
		else {
			result[i] += 1;
			break;
		}
	}
}

void func_15s_comp(int a[], int result[]) {
	// Subtract each digit from 15
	for (int i = MAX - 1; i >= 0; --i) {
		// No need to account for borrow because all hexadecimal digits are <= 15
		result[i] = 15 - a[i];
	}
}

void func_16s_comp(int a[], int result[]) {
	// Perform 15s comp and increment
	func_15s_comp(a, result);

	for (int i = MAX - 1; i >= 0; --i) {
		if (result[i] + 1 > 15) {
			result[i] = 0;
		}
		else {
			result[i] += 1;
			break;
		}
	}
}
