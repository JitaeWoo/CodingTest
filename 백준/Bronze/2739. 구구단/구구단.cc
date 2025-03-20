#include<stdio.h>

int main()
{
	int num1 = 0;

	scanf("%d", &num1);

	for (int i = 0; i < 9; i++)
		printf("%d * %d = %d\n", num1, i + 1, num1 * (i + 1));

	return 0;
}