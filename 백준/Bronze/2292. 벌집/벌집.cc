#include<stdio.h>

int main()
{
	int N = 0, temp = 1, plus = 6, count = 1;

	scanf("%d", &N);

	while (1)
	{
		if (temp >= N)
			break;

		temp += plus;
		plus += 6;
		count++;
	}

	printf("%d\n", count);

	return 0;
}

