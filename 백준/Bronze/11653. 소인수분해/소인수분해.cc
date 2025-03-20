#include<stdio.h>
#include<math.h>

int main()
{
	int N = 0;

	scanf("%d", &N);

	while (N != 1)
	{
		if (N % 2 == 0)
		{
			N /= 2;
			printf("2\n");
			continue;
		}

		for (int i = 3; i < 10000000; i += 2)
		{
			if (N % i == 0)
			{
				N /= i;
				printf("%d\n", i);
				break;
			}
		}
	}

	return 0;
}

