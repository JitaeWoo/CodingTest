#include<stdio.h>

int main() {
	int x = 0, y = 0, x1 = 0, x2 = 0, y1 = 0, y2 = 0;

	scanf("%d%d", &x, &y);
	x1 = x;
	y1 = y;

	scanf("%d%d", &x, &y);
	if (x1 == x)
		x1 = -1;
	else
		x2 = x;

	if (y1 == y)
		y1 = -1;
	else
		y2 = y;

	scanf("%d%d", &x, &y);
	if (x1 == -1)
		x2 = x;
	else if (x1 == x)
		x1 = -1;
	else
		x2 = -1;

	if (y1 == -1)
		y2 = y;
	else if (y1 == y)
		y1 = -1;
	else
		y2 = -1;

	if (x1 == -1)
		printf("%d ", x2);
	else
		printf("%d ", x1);

	if (y1 == -1)
		printf("%d\n", y2);
	else
		printf("%d\n", y1);

	return 0;
}