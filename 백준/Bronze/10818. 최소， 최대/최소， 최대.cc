#include<stdio.h>

int main()
{
	int num1 = 0, min = 1000000, max = -1000000, num2 = 0;

	scanf("%d", &num1);

	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &num2);

		if (num2 < min)
			min = num2;
		if (num2 > max)
			max = num2;
	}
		
	printf("%d %d\n", min, max);

	return 0;
}