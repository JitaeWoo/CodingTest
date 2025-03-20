#include<stdio.h>

int main()
{
	int N = 0, temp = 0;

	scanf("%d", &N);

	temp = N / 5;
	
	for (int i = temp; i >= 0; i--)
	{
		if ((N - i * 5) % 3 == 0)
		{
			printf("%d\n", i + (N - i * 5) / 3);
			return 0;
		}
	}

	printf("%d\n", -1);

	return 0;
}

