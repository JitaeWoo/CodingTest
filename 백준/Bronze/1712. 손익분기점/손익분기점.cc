#include<stdio.h>

int main()
{
	int A = 0, B = 0, C = 0;

	scanf("%d%d%d", &A, &B, &C);

	if (B >= C)
	{
		printf("%d\n", -1);
		return 0;
	}

	printf("%d\n", A / (C - B) + 1);

	return 0;
}

