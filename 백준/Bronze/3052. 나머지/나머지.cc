#include<stdio.h>

int main()
{
	int num1 = 0, arr[10] = { 0 }, count = 0;

	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &num1);

		num1 %= 42;

		arr[i] = num1;

		count++;

		for (int j = 0; j < i; j++)
			if (arr[j] == arr[i])
			{
				count--;
				break;
			}
	}

	printf("%d\n", count);


	return 0;
}