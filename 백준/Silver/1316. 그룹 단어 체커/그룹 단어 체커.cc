#include<stdio.h>

int main()
{
	int N = 0, count = 0;
	char arr[101] = { 0 };

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		int temp = 0;
		int check[26] = { 0 };
		int j = 0, is = 1;

		scanf("%s", arr);

		while (arr[j] != 0)
		{
			if (arr[j] == temp)
			{
				j++;
				continue;
			}

			if (check[arr[j] - 97] == 1)
			{
				is = 0;
				break;
			}

			temp = arr[j];
			check[arr[j] - 97] = 1;

			j++;
		}

		if (is != 0)
			count++;
	}

	printf("%d\n", count);

	return 0;
}

