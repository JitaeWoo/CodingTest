#include<stdio.h>
#include<math.h>

int main()
{
	int N = 0, M = 0, check = 0;

	scanf("%d", &M);
	scanf("%d", &N);

	if (M < 3)
	{
		printf("2\n");
		M = 3;
	}

	for (int i = M; i <= N; i++)
	{
		check = 1;

		for (int j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0)
			{
				check = 0;
				break;
			}
		}

		if (check)
			printf("%d\n", i);
	}

	return 0;
}

