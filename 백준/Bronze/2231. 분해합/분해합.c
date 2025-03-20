#include<stdio.h>

int main(void)
{
	int N = 0, temp = 0, creat = 0,result = 0;

	scanf("%d", &N);

	for (int i = 1; i < N; i++) {
		creat = i;
		temp = i;

		while (temp > 0) {
			creat += temp % 10;
			temp /= 10;
		}

		if (creat == N) {
			result = i;
			break;
		}
	}

	printf("%d\n", result);

	return 0;
}

