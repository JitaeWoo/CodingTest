#include<stdio.h>

int main()
{
	int num1 = 1, num2 = 0;

	while (1)
	{
		scanf("%d", &num1);
		scanf("%d", &num2);

		if (num1 == 0 && num2 == 0)
			break;

		printf("%d\n", num1 + num2);
	}
	
		
	return 0;
}