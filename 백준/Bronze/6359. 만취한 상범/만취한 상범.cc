#include <cstdio>
#include <vector>

using namespace std;

int main(void) {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		int N;
		scanf("%d", &N);

		vector<bool> rooms(N + 1, true);
		for (int r = 2; r <= N; ++r) {
			for (int mul = 1; r * mul <= N; ++mul) {
				rooms[r * mul] = !rooms[r * mul];
			}
		}

		int result = 0;
		for (int k = 1; k <= N; ++k) {
			if (rooms[k]) {
				++result;
			}
		}

		printf("%d\n", result);
	}

	return 0;
}