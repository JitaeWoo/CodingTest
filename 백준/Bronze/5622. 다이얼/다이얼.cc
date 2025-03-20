#include<stdio.h>

int main()
{
	int number[26] = { 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9 }, i = 0, sum = 0;
	char arr[16] = { 0 };

	scanf("%s", arr);

	while (arr[i] != 0)
	{
		sum += number[arr[i] - 65] + 1;
		i++;
	}

	printf("%d\n", sum);

	return 0;
}

