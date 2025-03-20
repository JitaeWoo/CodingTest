#include<stdio.h>

int main()
{
	int num1 = 0;
	double arr[1000] = { 0 }, max = 0, average = 0;

	scanf("%d", &num1);

	for (int i = 0; i < num1; i++)
	{
		scanf("%lf", &arr[i]);
		if (max < arr[i])
			max = arr[i];
	}

	for (int i = 0; i < num1; i++)
	{
		arr[i] = arr[i] / max * 100;
		average += arr[i];
	}

	average /= num1;

	printf("%f\n", average);

	return 0;
}