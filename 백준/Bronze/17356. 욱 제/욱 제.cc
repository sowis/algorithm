#include <cstdio>
#include <cmath>

using namespace std;

int main(void) {
	double A, B;
	scanf("%lf%lf", &A, &B);

	const double result = 1 / (1 + pow(10, (B - A) / 400));
	printf("%lf\n", result);

	return 0;
}