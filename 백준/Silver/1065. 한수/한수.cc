#include<stdio.h>

int main()
{
	int N = 0, count = 0;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		int num = i;

		while (num >= 100)
		{
			if (num / 100 - num % 100 / 10 != num % 100 / 10 - num % 10)
			{
				count--;
				break;
			}

			num /= 10;
		}

		count++;

	}

	printf("%d\n", count);

	return 0;
}

