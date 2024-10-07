#include <cstdio>
#include <vector>

using namespace std;

int main(void) {
	int N, M, K;
	scanf("%d%d%d", &N, &M, &K);

	vector<vector<int>> handshake(N, vector<int>(M));
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			scanf("%d", &handshake[y][x]);
		}
	}

	vector<int> counts(N, 0);
	for (int x = 0; x < M; ++x) {
		for (int y = 0; y < N; ++y) {
			counts[y] += handshake[y][x];

			if (counts[y] >= K) {
				printf("%d %d\n", y + 1, x + 1);
				return 0;
			}
		}
	}

	return 0;
}