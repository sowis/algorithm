#include <cstdio>
#include <vector>

using namespace std;

int main(void) {
	int N, M;
	scanf("%d%d", &N, &M);

	vector<int> counts(N + 1, 0);

	for (int i = 0; i < M; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);

		++counts[a];
		++counts[b];
	}

	for (int i = 1; i <= N; ++i) {
		printf("%d\n", counts[i]);
	}

	return 0;
}