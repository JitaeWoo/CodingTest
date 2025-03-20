#include<stdio.h>


int main()
{
	char arr[1000001] = { 0 };
	int count = 0, i = 0, isward = 0;

	gets(arr);

	while (arr[i] != 0)
	{
		if (arr[i] != ' ' && !isward)
		{
			count++;
			isward = 1;
		}
		else if (arr[i] == ' ' && isward)
		{
			isward = 0;
		}
		
		i++;
	}

	printf("%d\n", count);


	return 0;
}
