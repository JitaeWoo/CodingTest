#include<stdio.h>

int main()
{
	int M[1001] = {0};
	int A[1001] = {0};
	int N;
	int maxLen = 0;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
		scanf("%d", &A[i]);


	for (int i = 1; i <= N; i++)
	{
		int len = 0;
		for (int j = 0; j < i; j++)
		{
			if (A[i] > A[j] && M[j] > len)
				len = M[j];
		}
		M[i] = len + 1;

		if (maxLen < M[i])
			maxLen = M[i];
	}

	printf("%d", maxLen);
	
	return 0;
}

