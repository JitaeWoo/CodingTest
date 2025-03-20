#include<stdio.h>
#include<stdlib.h>

int main()
{
	char arr[101] = { 0 }, temp[2] = { 0 };
	int N = 0, sum = 0;

	scanf("%d", &N);
	scanf("%s", arr);

	for (int i = 0; i < N; i++)
	{
		temp[0] = arr[i];

		sum += atoi(temp);
	}

	printf("%d\n", sum);

	return 0;
}

