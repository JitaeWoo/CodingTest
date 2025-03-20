#include<stdio.h>

void solution(int*, int, int*, int);

int main()
{
	int T = 0, point = 11;
	int arr[1000] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 }; // 11개
	int numArr[10000] = { 0 };

	scanf("%d", &T);
	
	for (int i = 0; i < T; i++)
		scanf("%d", &numArr[i]);

	for (int i = 33 ; i < 1000; i += 2)
	{
		if (i % 3 != 0 && i % 5 != 0 && i % 7 != 0 && i % 11 != 0 && i % 13 != 0 && i % 17 != 0 && i % 19 != 0 && i % 23 != 0 && i % 29 != 0 && i % 31 != 0)
		{
			arr[point] = i;
			point++;
		}
	}

	for (int i = 0; i < T; i++)
	{
		solution(arr, point, numArr, i);
	}

	return 0;
}

void solution(int* arr, int point, int* numArr, int i)
{
	for (int j = 0; j < point; j++)
		for (int k = 0; k < point; k++)
			for (int l = 0; l < point; l++)
			{
				if (arr[j] + arr[k] + arr[l] == numArr[i])
				{
					printf("%d %d %d\n", arr[j], arr[k], arr[l]);
					return;
				}
			}
}