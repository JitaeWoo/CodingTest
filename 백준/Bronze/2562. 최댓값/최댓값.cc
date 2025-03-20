#include<stdio.h>

int main()
{
	int num1 = 0, max = 0, maxi = 0;

	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &num1);

		if (num1 > max)
		{
			max = num1;
			maxi = i + 1;
		}
	}

	printf("%d\n%d\n", max, maxi);
	

	return 0;
}