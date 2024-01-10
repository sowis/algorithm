#include <cstdio>

using namespace std;

int main(void) {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		int n;
		scanf("%d", &n);

		int result = 0;
		for (int mul_3 = 0; mul_3 <= n / 3; ++mul_3) {
			const int remain = n - (mul_3 * 3);
			result += (remain / 2) + 1;
		}

		printf("%d\n", result);
	}

	return 0;
}