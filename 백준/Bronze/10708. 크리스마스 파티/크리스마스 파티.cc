#include <cstdio>
#include <vector>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	int M;
	scanf("%d", &M);

	vector<int> target(M);
	for (int& t : target) {
		scanf("%d", &t);
	}

	vector<int> scores(N + 1, 0);
	for (int i = 0; i < M; ++i) {
		int no_match = 0;
		for (int id = 1; id <= N; ++id) {
			int select;
			scanf("%d", &select);

			if (select == target[i]) {
				++scores[id];
			}
			else {
				++no_match;
			}
		}

		scores[target[i]] += no_match;
	}

	for (int i = 1; i <= N; ++i) {
		printf("%d\n", scores[i]);
	}

	return 0;
}