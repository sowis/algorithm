#include <cstdio>

using namespace std;

void test_case(void) {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);

	int result = 0;
	for (int x = 1; x <= a; ++x) {
		for (int y = 1; y <= b; ++y) {
			for (int z = 1; z <= c; ++z) {
				if (x % y != y % z) {
					continue;
				}

				if (y % z != z % x) {
					continue;
				}

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