#include <cstdio>
#include <limits>
#include <algorithm>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	int min_score = numeric_limits<int>::max();
	int max_score = numeric_limits<int>::min();

	for (int i = 0; i < N; ++i) {
		int score;
		scanf("%d", &score);

		min_score = min(min_score, score);
		max_score = max(max_score, score);
	}

	printf("%d\n", max_score - min_score);

	return 0;
}