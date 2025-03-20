#include<stdio.h>

int main()
{
	int T = 0, N = 0, M = 0;
	int X[9] = { 0 }, Y[9] = { 0 };
	int arr[100] = { 0 };
	int x = 0, y = 0, count = 0;
	int mul = 1, mul2 = 1;
	int temp = 0;
	
	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		count = 0;
		x = 0;
		y = 0;

		scanf("%d", &N);
		scanf("%d", &M);

		for (int j = 0; j < M; j++)
			scanf("%d", &X[j]);

		for (int j = 0; j < M; j++)
			scanf("%d", &Y[j]);

		for (int j = 0; j < N; j++)
			scanf("%d", &arr[j]);

		mul = 1;

		for (int j = M - 1; j >= 0; j--)
		{
			x += X[j] * mul;
			y += Y[j] * mul;
			mul *= 10;
		}

		mul /= 10;
		for (int j = 0; j < N; j++)
		{
			mul2 = mul;
			temp = 0;
			for (int k = 0; k < M; k++)
			{
				if (j + k > N - 1)
					temp += arr[j + k - N] * mul2;
				else
					temp += arr[j + k] * mul2;
				mul2 /= 10;
			}
			if (temp >= x && temp <= y)
				count++;
		}
		printf("%d\n", count);
	}

	return 0;
}