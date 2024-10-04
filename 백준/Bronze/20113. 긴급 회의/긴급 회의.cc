#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	vector<int> votes(N + 1, 0);

	int max_count = 0;
	for (int i = 0; i < N; ++i) {
		int vote;
		scanf("%d", &vote);

		++votes[vote];
		max_count = max(max_count, votes[vote]);
	}

	int max_index = -1;
	for (int i = 1; i <= N; ++i) {
		if (votes[i] != max_count) {
			continue;
		}

		if (max_index != -1) {
			printf("skipped\n");
			return 0;
		}

		max_index = i;
	}

	printf("%d\n", max_index);

	return 0;
}