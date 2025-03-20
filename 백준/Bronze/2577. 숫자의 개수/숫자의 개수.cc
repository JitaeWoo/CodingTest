#include<stdio.h>

int main()
{
	int A = 0, B = 0, C = 0, arr[10] = { 0 }, mul = 0, temp = 0;

	scanf("%d %d %d", &A, &B, &C);

	mul = A * B * C;

	while (mul != 0)
	{
		temp = mul % 10;
		mul = mul / 10;

		arr[temp]++;
	}

	for (int i = 0; i < 10; i++)
		printf("%d\n", arr[i]);



	return 0;
}