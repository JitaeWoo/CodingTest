#include<stdio.h>

int main()
{
	int num1 = 0, num2 = 0;

	scanf("%d", &num1);
	scanf("%d", &num2);

	printf("%d\n%d\n%d\n%d\n", num1 * (num2 % 10), num1 * (num2 % 100 / 10), num1 * (num2 / 100), num1 * num2);

	return 0;
}