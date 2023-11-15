#include <cstdio>

using namespace std;

int main(void) {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		int n;
		scanf("%d", &n);

		for (int k = 0; k < n; ++k) {
			int a, b;
			scanf("%d%d", &a, &b);

			printf("%d %d\n", a + b, a * b);
		}
	}

	return 0;
}