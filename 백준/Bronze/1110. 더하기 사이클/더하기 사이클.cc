#include<stdio.h>

int main()
{
	int num1 = 0, num2 = -1, count = 0, temp = 0;

	scanf("%d", &num1);

	num2 = num1;

	do
	{
		temp = num2 % 10 * 10;

		if (num2 < 10)
			num2 *= 10;

		num2 = (num2 / 10 + num2 % 10) % 10 + temp;
		count++;
	} while (num2 != num1);

	printf("%d\n", count);
		
	return 0;
}