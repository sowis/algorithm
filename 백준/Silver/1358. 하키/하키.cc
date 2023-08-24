#include <cstdio>
#include <cmath>

using namespace std;

int main(void) {
	int w, h, x, y, p;
	scanf("%d%d%d%d%d", &w, &h, &x, &y, &p);

	int result = 0;
	for (int i = 0; i < p; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);

		if (x <= a && a <= x + w && y <= b && b <= y + h) {
			++result;
			continue;
		}

		if (pow(a - x, 2) + pow(b - (y + h / 2), 2) <= pow(h / 2, 2)) {
			++result;
			continue;
		}

		if (pow(a - (x + w), 2) + pow(b - (y + h / 2), 2) <= pow(h / 2, 2)) {
			++result;
			continue;
		}
	}

	printf("%d\n", result);

	return 0;
}