#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int w, h;
	int y, x;
	int t;

	scanf("%d%d", &w, &h);
	scanf("%d%d", &x, &y);
	scanf("%d", &t);

	x = (x + t) % (2 * w);
	y = (y + t) % (2 * h);

	if (x > w) {
		x = 2 * w - x;
	}

	if (y > h) {
		y = 2 * h - y;
	}

	printf("%d %d\n", x, y);

	return 0;
}