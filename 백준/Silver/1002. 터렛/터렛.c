#include<stdio.h>
#include<math.h>

int main() {
	int T = 0;

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		int x1, y1, r1, x2, y2, r2;
		double distance = 0;

		scanf("%d%d%d%d%d%d", &x1, &y1, &r1, &x2, &y2, &r2);

		if (x1 == x2 && y1 == y2 && r1 == r2) {
			printf("%d\n", -1);
			continue;
		}

		distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

		if (distance > r1 + r2)
			printf("0\n");
		else if (distance == r1 + r2)
			printf("1\n");
		else if (distance < r1 + r2) {
			if (distance == abs(r2 - r1))
				printf("1\n");
			else if (distance < abs(r2 - r1))
				printf("0\n");
			else
				printf("2\n");
		}	
	}

	return 0;
}