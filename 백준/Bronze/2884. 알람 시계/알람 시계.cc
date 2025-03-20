#include<stdio.h>

int main()
{
	int num1 = 0, num2 = 0;

	scanf("%d", &num1);
	scanf("%d", &num2);
	
	if (num2 >= 45)
		num2 -= 45;
	else
	{
		num2 += 15;
		if (num1 >= 1)
			num1 -= 1;
		else
			num1 += 23;
	}

	printf("%d %d", num1, num2);

	return 0;
}