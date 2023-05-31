#include <cstdio>

using namespace std;

int main(void) {
	int a, b, c, d, e, f;
	scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);

	for (int y = -999; y <= 999; ++y) {
		for (int x = -999; x <= 999; ++x) {
			if (a * x + b * y != c) {
				continue;
			}

			if (d * x + e * y != f) {
				continue;
			}

			printf("%d %d\n", x, y);
			return 0;
		}
	}

	return 0;
}