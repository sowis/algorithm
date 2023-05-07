#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int N;
vector<pair<int, int>> ingredients;

int cook(const int remain, vector<bool>& use) {
	if (remain == 0) {
		int sour = 1;
		int bitter = 0;
		for (int i = 0; i < N; ++i) {
			if (use[i] == false) {
				continue;
			}

			sour *= ingredients[i].first;
			bitter += ingredients[i].second;
		}

		return abs(sour - bitter);
	}

	int result = numeric_limits<int>::max();
	for (int i = 0; i < N; ++i) {
		if (use[i]) {
			continue;
		}

		use[i] = true;
		result = min(result, cook(remain - 1, use));
		use[i] = false;
	}

	return result;
}

int cook(const int remain) {
	vector<bool> use(N, false);
	return cook(remain, use);
}

int main(void) {
	scanf("%d", &N);

	ingredients = vector<pair<int, int>>(N);
	for (pair<int, int>& ingredient : ingredients) {
		scanf("%d%d", &ingredient.first, &ingredient.second);
	}

	int result = numeric_limits<int>::max();
	for (int remain = 1; remain <= N; ++remain) {
		result = min(result, cook(remain));
	}

	printf("%d\n", result);

	return 0;
}