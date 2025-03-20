#include<stdio.h>

int main()
{
	int num1 = 1, num2 = 0;

	while (scanf("%d %d", &num1, &num2) != EOF)
		printf("%d\n", num1 + num2);
	
		
	return 0;
}