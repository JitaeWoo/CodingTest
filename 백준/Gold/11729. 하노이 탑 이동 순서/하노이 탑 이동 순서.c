#include<stdio.h>

void hanoi(int, int, int, int);

int main(void)
{
	int N = 0, count = 1;

	scanf("%d", &N);
	
	for (int i = 1; i < N; i++)
		count = count * 2 + 1;

	printf("%d\n", count);
	hanoi(N, 1, 2, 3);

	return 0;
}

void hanoi(int N, int start, int temp, int finish) {
	if (N == 2) {
		printf("%d %d\n", start, temp);
		printf("%d %d\n", start, finish);
		printf("%d %d\n", temp, finish);
	}
	else if (N >= 3) {
		hanoi(N - 1, start, finish, temp);
		printf("%d %d\n", start, finish);
		hanoi(N - 1, temp, start, finish);
	}
	else printf("1 3\n");
}