#include <cstdio>
#include <algorithm>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	int result = 0;
	for (int i = 0; i < N; ++i) {
		int a, d, g;
		scanf("%d%d%d", &a, &d, &g);

		int score = a * (d + g);
		if (a == d + g) {
			score *= 2;
		}

		result = max(result, score);
	}

	printf("%d\n", result);

	return 0;
}