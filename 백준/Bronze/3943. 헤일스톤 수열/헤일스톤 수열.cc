#include <cstdio>
#include <algorithm>

using namespace std;

void test_case(void) {
	int n;
	scanf("%d", &n);

	int result = n;
	while (n != 1) {
		if (n % 2) {
			n = 3 * n + 1;
		}
		else {
			n /= 2;
		}

		result = max(result, n);
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