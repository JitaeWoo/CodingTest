#include<stdio.h>

int main()
{
	int num1 = 0, num2 = 0, num3 = 0;

	scanf("%d", &num1);
	scanf("%d", &num2);
	scanf("%d", &num3);

	printf("%d\n%d\n%d\n%d\n", (num1 + num2)%num3, ((num1%num3) + (num2 % num3)) % num3, (num1 * num2) % num3, ((num1 % num3) * (num2 % num3)) % num3);

	return 0;
}