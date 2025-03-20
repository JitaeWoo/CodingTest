#include<stdio.h>

int main() {
	int N = 0;

	scanf("%d", &N);

	printf("%d\n", factorial(N));

	return 0;
}

int factorial(int N) {
	if (N <= 1) return 1;

	return N * factorial(N - 1);
}