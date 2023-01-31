#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int K;
	scanf("%d", &K);

	for (int i = 0; i < K; ++i) {
		int N;
		scanf("%d", &N);

		vector<int> scores(N);
		for (int& score : scores) {
			scanf("%d", &score);
		}

		sort(scores.begin(), scores.end());

		int largest_gap = 0;
		for (int k = 1; k < N; ++k) {
			largest_gap = max(largest_gap, scores[k] - scores[k - 1]);
		}

		printf("Class %d\n", i + 1);
		printf("Max %d, Min %d, Largest gap %d\n", scores[N - 1], scores[0], largest_gap);
	}

	return 0;
}