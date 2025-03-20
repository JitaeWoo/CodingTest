#include<stdio.h>

int main()
{
	double num1 = 0, num2 = 0;

	scanf("%lf", &num1);
	scanf("%lf", &num2);

	printf("%.15f\n", num1 / num2);

	return 0;
}