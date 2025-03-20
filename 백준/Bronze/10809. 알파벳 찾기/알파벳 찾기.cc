#include<stdio.h>
#include<stdlib.h>

int main()
{
	int result[26] = { 0 }, j = 0;
	char arr[101] = { 0 };

	for (int i = 0; i < 26; i++)
		result[i] = -1;

	scanf("%s", arr);

	while (arr[j] != '\0')
	{
		if (result[arr[j] - 97] == -1)
			result[arr[j] - 97] = j;
		j++;
	}

	for (int i = 0; i < 26; i++)
		printf("%d ", result[i]);

	return 0;
}
