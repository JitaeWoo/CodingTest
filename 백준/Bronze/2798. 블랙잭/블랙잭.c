#include<stdio.h>

int main(void)
{
	int N_list[100] = { 0 };
	int N = 0, M = 0, result = 0;

	scanf("%d%d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%d", &N_list[i]);
	}

	for(int i = 0; i < N - 2; i++) 
		for(int j = i + 1; j < N - 1; j++)
			for (int k = j + 1; k < N; k++){
				int temp = N_list[i] + N_list[j] + N_list[k];
				if (result < temp && temp <= M)
					result = temp;
			}

	printf("%d\n", result);

	return 0;
}

