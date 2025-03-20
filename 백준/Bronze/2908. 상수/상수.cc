#include<stdio.h>
#include<stdlib.h>

int main()
{
	char arr[4] = { 0 }, temp = 0;
	int num1 = 0, num2 = 0;

	scanf("%s", &arr);

	temp = arr[0];
	arr[0] = arr[2];
	arr[2] = temp;

	num1 = atoi(arr);

	scanf("%s", &arr);

	temp = arr[0];
	arr[0] = arr[2];
	arr[2] = temp;

	num2 = atoi(arr);

	if (num1 > num2)
		printf("%d\n", num1);
	else
		printf("%d\n", num2);

	return 0;
}

