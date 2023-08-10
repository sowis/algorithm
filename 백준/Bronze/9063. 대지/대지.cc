#include <cstdio>
#include <limits>
#include <algorithm>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	int y_min = numeric_limits<int>::max();
	int y_max = numeric_limits<int>::min();
	int x_min = numeric_limits<int>::max();
	int x_max = numeric_limits<int>::min();

	for (int i = 0; i < N; ++i) {
		int y, x;
		scanf("%d%d", &y, &x);

		y_min = min(y_min, y);
		y_max = max(y_max, y);
		x_min = min(x_min, x);
		x_max = max(x_max, x);
	}

	const int result = (y_max - y_min) * (x_max - x_min);
	printf("%d\n", result);

	return 0;
}