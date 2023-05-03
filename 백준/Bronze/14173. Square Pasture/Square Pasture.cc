#include <cstdio>
#include <algorithm>

using namespace std;

int main(void) {
	int x11, y11, x12, y12;
	int x21, y21, x22, y22;

	scanf("%d%d%d%d", &x11, &y11, &x12, &y12);
	scanf("%d%d%d%d", &x21, &y21, &x22, &y22);

	int x1, y1, x2, y2;
	x1 = min(x11, x21);
	y1 = min(y11, y21);
	x2 = max(x12, x22);
	y2 = max(y12, y22);

	const int width = abs(x2 - x1);
	const int height = abs(y2 - y1);

	const int sqr = max(width, height);
	const int result = sqr * sqr;

	printf("%d\n", result);

	return 0;
}