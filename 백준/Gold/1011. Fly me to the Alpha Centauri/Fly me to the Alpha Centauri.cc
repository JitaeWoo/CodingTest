#include<stdio.h>

int main()
{
	int T = 0, X = 0, Y = 0, dif = 0, temp = 0;
	unsigned int len = 0;

	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		len = 0;

		scanf("%d%d", &X, &Y);

		dif = Y - X;

		for (temp = 1; len < dif; temp++)
			len += (temp + 1) / 2;

		printf("%d\n", temp - 1);
	}

	return 0;
}

