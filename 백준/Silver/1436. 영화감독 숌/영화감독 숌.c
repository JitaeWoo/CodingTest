#include<stdio.h>

int main(void)
{
	int N = 0, num = 666, temp = 0, temp2 = 0, check = 0;

	scanf("%d", &N);

	while (1) {
		temp = num;

		check = 0;
		while (temp > 0) {
			if (temp % 10 == 6)
				check++;
			else
				check = 0;

			if (check >= 3) {
				temp2++;
				break;
			}
			temp /= 10;
		}

		if (temp2 == N) {
			printf("%d\n", num);
			break;
		}

		num++;
	}

	return 0;
}