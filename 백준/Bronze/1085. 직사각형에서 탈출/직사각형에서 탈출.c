#include<stdio.h>

int main() {
	int x = 0, y = 0, w = 0, h = 0;
	int result = 0;

	scanf("%d%d%d%d", &x, &y, &w, &h);
	
	result = x;

	if (result > y)
		result = y;
	if (result > w - x)
		result = w - x;
	if (result > h - y)
		result = h - y;

	printf("%d\n", result);
	
	return 0;
}