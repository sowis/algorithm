#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int hits[6][3] = {
	{ 9, 3, 1 },
	{ 9, 1, 3 },
	{ 3, 9, 1 },
	{ 3, 1, 9 },
	{ 1, 9, 3 },
	{ 1, 3, 9 },
};

int main(void) {
	int N;
	scanf("%d", &N);

	vector<vector<vector<int>>> cache(61, vector<vector<int>>(61, vector<int>(61, 987654321)));
	vector<int> hp(3, 0);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &hp[i]);
	}

	cache[hp[0]][hp[1]][hp[2]] = 0;
	for (int a = 60; a >= 0; --a) {
		for (int b = 60; b >= 0; --b) {
			for (int c = 60; c >= 0; --c) {
				for (int i = 0; i < 6; ++i) {
					const int next_hp_1 = max(0, a - hits[i][0]);
					const int next_hp_2 = max(0, b - hits[i][1]);
					const int next_hp_3 = max(0, c - hits[i][2]);

					cache[next_hp_1][next_hp_2][next_hp_3] = min(cache[a][b][c] + 1, cache[next_hp_1][next_hp_2][next_hp_3]);
				}
			}
		}
	}

	printf("%d", cache[0][0][0]);

	return 0;
}