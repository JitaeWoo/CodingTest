#include<stdio.h>
#include<math.h>

int main()
{
	int M = 0, N = 0, min = 0, sum = 0, check = 0;

	scanf("%d", &M);
	scanf("%d", &N);

	for (int i = M; i <= N; i++)
	{
		check = 1;

		if (i == 1)
			continue;

		for (int j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0)
			{
				check = 0;
				break;
			}
		}

		if (check)
		{
			if (min == 0)
				min = i;

			sum += i;
		}
	}
	if (min != 0)
		printf("%d\n%d\n", sum, min);
	else
		printf("-1");

	return 0;
}

