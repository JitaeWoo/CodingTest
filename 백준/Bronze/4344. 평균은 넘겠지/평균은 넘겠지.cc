#include<stdio.h>

int main()
{
	int T = 0, num1 = 0, score[1000] = { 0 }, win = 0, lose = 0;
	double ave = 0, rate = 0;

	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		ave = 0;
		rate = 0;
		win = 0;
		lose = 0;

		scanf("%d", &num1);

		for (int j = 0; j < num1; j++)
		{
			scanf("%d", &score[j]);
			ave += score[j];
		}
		
		ave /= num1;

		for (int j = 0; j < num1; j++)
			if (ave < score[j])
				win++;

		rate = (double)win / num1 * 100;

		printf("%.3f%\n", rate);
	}

	return 0;
}