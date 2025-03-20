#include<stdio.h>

int main()
{
	int T = 0, K = 0, N = 0, arr[15][14] = { 0 };

	scanf("%d", &T);

	for (int i = 0; i < 14; i++)
		arr[0][i] = i + 1;

	for (int i = 1; i < 15; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			for (int k = 0; k < j + 1; k++)
			{
				arr[i][j] += arr[i - 1][k];
			}
		}
	}

	for (int i = 0; i < T; i++)
	{
		scanf("%d%d", &K, &N);

		printf("%d\n", arr[K][N - 1]);
	}

	return 0;
}

