#include<stdio.h>

int main()
{
	int T = 0;
	int m_n[2] = { 0 };
	int box[100][100] = { 0 };
	int count = 0;

	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		count = 0;
		
		for (int j = 0; j < 2; j++)
			scanf("%d", &m_n[j]);

		for (int j = 0; j < m_n[0]; j++)
			for (int k = 0; k < m_n[1]; k++)
				scanf("%d", &box[j][k]);

		for (int n = 0; n < m_n[1]; n++)
			for (int m = m_n[0] - 2; m >= 0; m--)
				for (int j = m; j < m_n[0] - 1; j++)
					if (box[j][n] == 1 && box[j + 1][n] == 0)
					{
						box[j][n] = 0;
						box[j + 1][n] = 1;
						count++;
					}
					else
						break;

		printf("%d\n", count);
	}

	return 0;
}