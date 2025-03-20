#include<stdio.h>

int main()
{
	int T = 0, H = 0, W = 0, N = 0, result = 0;

	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		scanf("%d%d%d", &H, &W, &N);

		result = N / H + N % H * 100 + 1;

		if (N % H == 0)
			result += H * 100 - 1;

		printf("%d\n", result);
	}

	return 0;
}
