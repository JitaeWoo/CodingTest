#include<stdio.h>

int main()
{
	int A = 0, B = 0, V = 0, C = 0, result = 1;

	scanf("%d%d%d", &A, &B, &V);

	C = A - B;

	result = V / C - (A / C - 1);

	if (V % C != 0)
	{
		result++;
		if (V % C <= A % C)
			result--;
	}

	printf("%d\n", result);

	return 0;
}