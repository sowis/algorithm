#include <cstdio>
#include <cmath>

int main(void) {
	long long area;
	scanf("%lld\n", &area);

	const double result = sqrt(area) * 4;
	printf("%.7lf\n", result);

	return 0;
}