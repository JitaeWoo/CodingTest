#include<stdio.h>


int main()
{
	char arr[1000001] = { 0 };
	int result[26] = { 0 }, i = 0, max = 0, maxi = 0;

	scanf("%s", &arr);

	while (arr[i] != 0)
	{
		if (arr[i] < 95)
			result[arr[i] - 65]++;
		else
			result[arr[i] - 97]++;

		i++;
	}

	for (i = 0; i < 26; i++)
	{
		if (result[i] > max)
		{
			max = result[i];
			maxi = i;
		}
		else if (result[i] == max)
			maxi = -2;
	}

	printf("%c\n", maxi + 65);

	return 0;
}

