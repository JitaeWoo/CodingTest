#include<stdio.h>

int main()
{
	int num1 = 0;

	scanf("%d", &num1);

	for (int i = 0; i < num1; i++)
		printf("%d\n", num1 - i);

	return 0;
}