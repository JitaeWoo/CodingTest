#include<stdio.h>

int main() {
	int side1 = 0, side2 = 0, side3 = 0;

	while (1) {
		scanf("%d%d%d", &side1, &side2, &side3);

		if (side1 == 0)
			break;

		if (side1 > side2) {
			int temp = side1;
			side1 = side2;
			side2 = temp;
		}

		if (side2 > side3) {
			int temp = side2;
			side2 = side3;
			side3 = temp;
		}

		if (side1 * side1 + side2 * side2 == side3 * side3)
			printf("right\n");
		else
			printf("wrong\n");
	}

	return 0;
}