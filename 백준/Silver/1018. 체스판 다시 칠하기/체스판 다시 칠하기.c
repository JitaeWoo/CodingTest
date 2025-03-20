#include<stdio.h>

int main(void)
{
	char chess[50][50] = { 0 };
	int N = 0, M = 0, result = 64, sum = 0;
	char color = 'W';

	scanf("%d%d", &N, &M);
	getchar();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			scanf("%c", &chess[i][j]);
		getchar();
	}	
			
	for (int i = 0; i < N - 7; i++)
		for (int j = 0; j < M - 7; j++)
			for (int h = 0; h < 2; h++) {
				sum = 0;

				for (int k = i; k < i + 8; k++) {
					for (int l = j; l < j + 8; l++) {
						if (color != chess[k][l]) {
							sum++;
						}

						if (color == 'W')
							color = 'B';
						else
							color = 'W';
					}

					if (color == 'W')
						color = 'B';
					else
						color = 'W';
				}				

				if (color == 'W')
					color = 'B';
				else
					color = 'W';

				if (result > sum)
					result = sum;
			}

	printf("%d\n", result);

	return 0;
}

