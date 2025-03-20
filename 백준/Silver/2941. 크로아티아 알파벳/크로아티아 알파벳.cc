#include<stdio.h>

int main()
{
	char arr[101] = { 0 };
	int length = 0, i = 0;

	scanf("%s", arr);

	while (arr[i] != 0)
	{
		if (arr[i] == '-')
			length--;

		if (arr[i] == 'j' && i > 0)
			if (arr[i - 1] == 'l' || arr[i - 1] == 'n')
				length--;

		if (arr[i] == '=')
		{
			length--;
			if (i > 1)
				if (arr[i - 1] == 'z' && arr[i - 2] == 'd')
					length--;
		}

		length++;
		i++;
	}

	printf("%d\n", length);

	return 0;
}

