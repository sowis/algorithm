#include <cstdio>
#include <vector>

using namespace std;

int main(void) {
	int N, S, R;
	scanf("%d%d%d", &N, &S, &R);

	vector<bool> brk(N + 2, false);
	vector<bool> more(N + 2, false);

	for (int i = 0; i < S; ++i) {
		int team;
		scanf("%d", &team);

		brk[team] = true;
	}

	for (int i = 0; i < R; ++i) {
		int team;
		scanf("%d", &team);

		more[team] = true;
	}

	for (int i = 1; i <= N; ++i) {
		if (brk[i] && more[i]) {
			brk[i] = false;
			more[i] = false;
		}
	}

	for (int i = 1; i <= N; ++i) {
		if (brk[i] == false) {
			continue;
		}

		if (more[i - 1]) {
			more[i - 1] = false;
			brk[i] = false;
			continue;
		}

		if (more[i + 1]) {
			more[i + 1] = false;
			brk[i] = false;
			continue;
		}
	}

	int result = 0;
	for (int i = 1; i <= N; ++i) {
		if (brk[i]) {
			++result;
		}
	}

	printf("%d\n", result);

	return 0;
}