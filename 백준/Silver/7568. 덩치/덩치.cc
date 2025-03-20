#include<stdio.h>

typedef struct Person{
	int height;
	int weight;
} person;

int main(void)
{
	person arr[50];
	int rank[50] = { 0 };
	int N = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) 
		scanf("%d%d", &arr[i].weight, &arr[i].height);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) 
			if (arr[i].height < arr[j].height && arr[i].weight < arr[j].weight)
				rank[i]++;

	for (int i = 0; i < N; i++)
		printf("%d ", rank[i] + 1);

	return 0;
}

