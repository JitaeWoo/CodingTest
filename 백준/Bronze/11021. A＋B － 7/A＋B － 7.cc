#include<stdio.h>

int main()
{
	int num1 = 0, num2 = 0, T = 0;

	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		scanf("%d", &num1);
		scanf("%d", &num2);

		printf("Case #%d: %d\n", i + 1, num1 + num2);
	}

	return 0;
}