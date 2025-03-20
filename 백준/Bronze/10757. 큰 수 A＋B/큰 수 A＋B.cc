#include<stdio.h>

int main()
{
	char* big = NULL, *small = NULL;
	char A[10002] = { 0 }, B[10002] = { 0 }, result[10003] = { 0 };
	int A_len = 0, B_len = 0, max = 0, dif = 0, temp = 0, isten = 0;

	scanf("%s%s", A, B);

	while (A[A_len] != 0)
		A_len++;
	A_len--;

	while (B[B_len] != 0)
		B_len++;
	B_len--;
	

	if (A_len > B_len)
	{
		big = A;
		small = B;
		dif = A_len - B_len;
		max = A_len;
	}
	else
	{
		big = B;
		small = A;
		dif = B_len - A_len;
		max = B_len;
	}
	

	for (int i = max; i >= dif; i--)
	{
		temp = big[i] + small[i - dif] - 48 * 2;

		if (isten == 1)
		{
			isten = 0;
			temp++;
		}

		if (temp >= 10)
			isten = 1;

		result[i + 1] = temp % 10 + 48;
	}

	for (int i = dif - 1; i >= 0; i--)
	{
		temp = big[i] - 48;

		if (isten == 1)
		{
			isten = 0;
			temp++;
		}

		if (temp >= 10)
			isten = 1;

		result[i + 1] = temp % 10 + 48;
	}

	if (isten == 1)
		printf("1");

	for (int i = 1; i < max + 2; i++)
		printf("%c", result[i]);

	return 0;
}

