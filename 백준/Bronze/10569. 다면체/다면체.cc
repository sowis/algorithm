#include <cstdio>

int main(void) {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		int v, e;
		scanf("%d%d", &v, &e);

		const int result = 2 - v + e;
		printf("%d\n", result);
	}

	return 0;
}