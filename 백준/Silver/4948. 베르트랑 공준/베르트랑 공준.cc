#include<stdio.h>
#include<math.h>

int main()
{
	int N = 0, count = 0, check = 0;

	while (1)
	{
		count = 0;

		scanf("%d", &N);

		if (!N)
			break;

		if (N == 1)
		{
			printf("1\n");
			continue;
		}
		

		for (int i = N + 1; i <= 2 * N; i++)
		{
			check = 1;

			if (i % 2 == 0)
				continue;

			for (int j = 3; j <= sqrt(i); j += 2)
			{
				if (i % j == 0)
				{
					check = 0;
					break;
				}
			}

			if (check)
				count++;

			if (i % 2 == 0)
				i++;
		}

		printf("%d\n", count);
	}


	return 0;
}

