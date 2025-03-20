#include<stdio.h>

int main()
{
	int arr[10001] = { 0 };

	for (int i = 1; i <= 10000; i++)
		arr[i] = i;

	for (int i = 1; i <= 10000; i++)
	{
		int num = i;
		int temp = i;


		while (temp != 0)
		{
			num += temp % 10;
			temp /= 10;
		}

		if (num <= 10000)
			arr[num] = 0;
	}

	for (int i = 1; i <= 10000; i++)
		if (arr[i] != 0)
			printf("%d\n", arr[i]);

	return 0;
}

