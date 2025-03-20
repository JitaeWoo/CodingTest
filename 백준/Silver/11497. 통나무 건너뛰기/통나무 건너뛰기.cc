#include<stdio.h>

int main()
{
	int T = 0, num = 0;
	int arr[10000] = { 0 };
	int sol[10000] = { 0 };

	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		scanf("%d", &num);

		for (int j = 0; j < num; j++)
			scanf("%d", &arr[j]);

		for (int j = 1; j < num; j++)
		{
			for (int k = j; k > 0; k--)
			{
				if (arr[k] < arr[k - 1])
				{
					int temp = arr[k];
					arr[k] = arr[k - 1];
					arr[k - 1] = temp;
				}
				else
					break;
			}
		}

		for (int j = 0; j < num - 2; j++)
			if (arr[j + 2] - arr[j] > sol[i])
				sol[i] = arr[j + 2] - arr[j];
	}

	for (int i = 0; i < T; i++)
		printf("%d\n", sol[i]);

	return 0;
}