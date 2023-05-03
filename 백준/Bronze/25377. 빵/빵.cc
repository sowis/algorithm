#include <cstdio>
#include <limits>
#include <algorithm>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	int min_time = numeric_limits<int>::max();

	for (int i = 0; i < N; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);

		if (a <= b) {
			min_time = min(min_time, b);
		}
	}

	if (min_time == numeric_limits<int>::max()) {
		min_time = -1;
	}

	printf("%d\n", min_time);

	return 0;
}