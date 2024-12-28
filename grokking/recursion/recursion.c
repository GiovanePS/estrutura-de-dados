#include <stdio.h>

int factorial(int);

int main(void) {
	unsigned int result = factorial(30);

	printf("%d\n", result);
	return 0;
}

int factorial(int n) {
	if (n == 1) {
		return 1;
	}

	return n * factorial(n - 1);
}
