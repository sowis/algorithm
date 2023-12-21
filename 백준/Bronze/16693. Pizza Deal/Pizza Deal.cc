#include <cstdio>

int main(void) {
	double a1, p1, r1, p2;
	scanf("%lf%lf%lf%lf", &a1, &p1, &r1, &p2);

	if (a1 / p1 < (r1 * r1 * 3.14159265358979) / p2) {
		printf("Whole pizza");
	}
	else {
		printf("Slice of pizza");
	}

	return 0;
}