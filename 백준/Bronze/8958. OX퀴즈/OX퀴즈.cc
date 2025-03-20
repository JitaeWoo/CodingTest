#include<stdio.h>

int main()
{
	int T = 0, score = 0, temp = 0, j = 0;

	char result[81] = "";

	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		scanf("%s", result);
		j = 0;
		score = 0;
		temp = 0;
		while (result[j] != '\0')
		{
			if (result[j] == 'O')
				temp++;
			else
				temp = 0;

			score += temp;
			j++;
		}

		printf("%d\n", score);
	}

	return 0;
}