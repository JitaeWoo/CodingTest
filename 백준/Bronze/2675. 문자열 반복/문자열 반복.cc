#include<stdio.h>

int main()
{
	int T = 0, R = 0;
	char arr[21] = { 0 };

	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		int j = 0;

		scanf("%d", &R);
		scanf("%s", arr);

		while (arr[j] != 0)
		{
			for (int k = 0; k < R; k++)
				printf("%c", arr[j]);
			j++;
		}

		printf("\n");
	}

	return 0;
}
