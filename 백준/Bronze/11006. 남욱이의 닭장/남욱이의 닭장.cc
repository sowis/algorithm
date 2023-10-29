#include <cstdio>

int main(void) {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);

		for (int u = 0; u <= b; ++u) {
			const int t = b - u;

			if (u + t * 2 == a) {
				printf("%d %d\n", u, t);
				break;
			}
		}
	}

	return 0;
}