#include<stdio.h>

int main()
{
	int N = 0, num1 = 0, count = 0;
	int arr[1000] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num1);

		if (num1 < 32)
		{
			for (int i = 0; i < 11; i++)
				if (num1 == arr[i])
					count++;
		}
		else
		{
			if (num1 % 2 != 0 && num1 % 3 != 0 && num1 % 5 != 0 && num1 % 7 != 0 && num1 % 11 != 0 && num1 % 13 != 0 && num1 % 17 != 0 &&
				num1 % 19 != 0 && num1 % 23 != 0 && num1 % 29 != 0 && num1 % 31 != 0)
				count++;
		}
	}

	printf("%d\n", count);

	return 0;
}

