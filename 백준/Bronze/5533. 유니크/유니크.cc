#include <cstdio>
#include <vector>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	vector<vector<int>> datas(N, vector<int>(3));
	for (int i = 0; i < N; ++i) {
		for (int k = 0; k < 3; ++k) {
			scanf("%d", &datas[i][k]);
		}
	}

	vector<int> scores(N, 0);
	for (int game = 0; game < 3; ++game) {
		for (int i = 0; i < N; ++i) {
			bool ok = true;
			for (int k = 0; k < N; ++k) {
				if (i == k) {
					continue;
				}

				if (datas[i][game] == datas[k][game]) {
					ok = false;
					break;
				}
			}

			if (ok) {
				scores[i] += datas[i][game];
			}
		}
	}

	for (const int score : scores) {
		printf("%d\n", score);
	}

	return 0;
}