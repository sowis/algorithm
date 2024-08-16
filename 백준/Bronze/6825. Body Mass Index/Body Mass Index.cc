#include <cstdio>

int main(void) {
	double h, w;
	scanf("%lf%lf", &w, &h);

	const double bmi = w / (h * h);

	if (bmi < 18.5) {
		printf("Underweight\n");
	}
	else if (bmi > 25) {
		printf("Overweight\n");
	}
	else {
		printf("Normal weight\n");
	}

	return 0;
}