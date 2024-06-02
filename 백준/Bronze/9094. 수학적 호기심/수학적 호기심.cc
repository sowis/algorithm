#include <cstdio>

using namespace std;

void test_case(void) {
	int n, m;
	scanf("%d%d", &n, &m);

	int result = 0;
	for (int a = 1; a < n - 1; ++a) {
		for (int b = a + 1; b < n; ++b) {
			if ((a * a + b * b + m) % (a * b) == 0) {
				++result;
			}
		}
	}

	printf("%d\n", result);
}

int main(void) {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		test_case();
	}

	return 0;
}