#include <cstdio>
#include <unordered_set>

using namespace std;

unordered_set<int> avoids[201];

int main(void) {
	int N, M;
	scanf("%d%d", &N, &M);

	for (int i = 0; i < M; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);

		avoids[a].insert(b);
		avoids[b].insert(a);
	}

	int result = 0;
	for (int a = 1; a <= N - 1; ++a) {
		for (int b = a + 1; b <= N - 1; ++b) {
			if (avoids[a].find(b) != avoids[a].end()) {
				continue;
			}

			for (int c = b + 1; c <= N; ++c) {
				if (avoids[a].find(c) != avoids[a].end()) {
					continue;
				}

				if (avoids[b].find(c) != avoids[b].end()) {
					continue;
				}

				++result;
			}
		}
	}

	printf("%d\n", result);

	return 0;
}