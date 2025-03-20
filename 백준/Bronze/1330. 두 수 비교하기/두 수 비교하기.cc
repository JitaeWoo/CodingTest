#include<stdio.h>

int main()
{
	int num1 = 0, num2 = 0;

	scanf("%d", &num1);
	scanf("%d", &num2);

	if (num1 < num2)
		printf("<");
	else if (num1 > num2)
		printf(">");
	else
		printf("==");

	return 0;
}