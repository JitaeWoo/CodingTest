#include<stdio.h>

int main()
{
	int X = 0, temp = 1, plus = 2, i = 1, front = 0, back = 0;

	scanf("%d", &X);

	while (1)
	{
		if (temp >= X)
		{
			if (i % 2 == 0)
			{
				front = i;
				back = 1;

				while (temp != X)
				{
					temp--;
					back++;
					front--;
				}
			}
			else
			{
				front = 1;
				back = i;

				while (temp != X)
				{
					temp--;
					back--;
					front++;
				}
			}

			break;
		}

		temp += plus;
		plus++;
		i++;
	}

	printf("%d/%d\n", front, back);

	return 0;
}

