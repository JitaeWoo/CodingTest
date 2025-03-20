#define _USE_MATH_DEFINES
#include<stdio.h>
#include<math.h>


int main() {
	int R = 0;

	scanf("%d", &R);

	printf("%f\n", R * R * M_PI);
	printf("%f\n", R * R * 2.0);

	return 0;
}