#include<stdio.h>

int arr[21] = { 0, 1 };

int main() {
	int n = 0;

	scanf("%d", &n);

	printf("%d\n", fibonacci(n));

	return 0;
}

int fibonacci(int n) {
	if (n <= 0) return 0;
	if (n == 1) return 1;

	if (arr[n] != 0)
		return arr[n];

	arr[n] = fibonacci(n - 1) + fibonacci(n - 2);

	return arr[n];
}