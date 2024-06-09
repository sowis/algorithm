#include <cstdio>
#include <cmath>

using namespace std;

const int values[5] = { 50 ,20, 10, 5, 1 };

void test_case(void) {
	double a, b;
	scanf("%lf%lf", &a, &b);

	int target = (int)floor(abs(a - b));

	for (int i = 0; i < 5; ++i) {
		const int count = target / values[i];
		printf("%d-$%d", count, values[i]);
		target -= count * values[i];


		if (i != 4) {
			printf(", ");
		}
	}

	printf("\n");
}

int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		test_case();
	}

	return 0;
}