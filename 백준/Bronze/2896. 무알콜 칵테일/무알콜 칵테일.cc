#include <cstdio>
#include <algorithm>

using namespace std;

int main(void) {
	double a, b, c, l, j, k;
	scanf("%lf%lf%lf%lf%lf%lf", &a, &b, &c, &l, &j, &k);

	const double make = min(min(a / l, b / j), c / k);
	printf("%lf %lf %lf\n", a - make * l, b - make * j, c - make * k);

	return 0;
}