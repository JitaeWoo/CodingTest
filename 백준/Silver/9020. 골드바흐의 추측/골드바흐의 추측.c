#include<stdio.h>
#include<math.h>

int main() {
	int prime[1229] = { 0 };
	int T = 0, n = 0, p_count = 0, num1 = 0, num2 = 0, print1 = 0, print2 = 0;
	int is_prime = 1;

	for (int i = 2; i < 10000; i++) {
		is_prime = 1;
		for (int j = 2; j <= sqrt(i); j++)
			if (i % j == 0) {
				is_prime = 0;
				break;
			}

		if (is_prime) {
			prime[p_count] = i;
			p_count++;
		}
	}

	scanf("%d", &T);

	for (int k = 0; k < T; k++) {
		scanf("%d", &n);

		for (int i = 0; i < 1229; i++)
			for (int j = i; j < 1229; j++) {
				if (prime[i] + prime[j] > n) break;

				if (prime[i] + prime[j] == n) {
					print1 = prime[i];
					print2 = prime[j];
				}
			}
				

		printf("%d %d\n", print1, print2);
	}

	return 0;
}