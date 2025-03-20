#include<stdio.h>

int main()
{
	int num1 = 0, num2 = 0, T = 0;

	scanf("%d", &T);
	scanf("%d", &num1);

	for (int i = 0; i < T; i++)
	{
		scanf("%d", &num2);

		if (num2 < num1)
			printf("%d ", num2);
	}

	return 0;
}