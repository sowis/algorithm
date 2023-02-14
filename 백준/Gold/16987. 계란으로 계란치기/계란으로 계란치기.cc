#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int solve(vector<pair<int, int>>& eggs, const int index = 0) {
	if (index == N) {
		int result = 0;
		for (const pair<int, int>& egg : eggs) {
			if (egg.first <= 0) {
				++result;
			}
		}

		return result;
	}

	if (eggs[index].first <= 0) {
		return solve(eggs, index + 1);
	}

	int result = 0;
	const pair<int, int> me = eggs[index];

	for (int target_index = 0; target_index < N; ++target_index) {
		if (eggs[target_index].first <= 0) {
			continue;
		}

		if (target_index == index) {
			continue;
		}

		const pair<int, int> target = eggs[target_index];
		eggs[index].first -= eggs[target_index].second;
		eggs[target_index].first -= eggs[index].second;

		result = max(result, solve(eggs, index + 1));

		eggs[index] = me;
		eggs[target_index] = target;
	}

	if (index == N - 1) {
		result = max(result, solve(eggs, index + 1));
	}

	return result;
}

int main(void) {
	scanf("%d", &N);

	vector<pair<int, int>> eggs(N);
	for (pair<int, int>& egg : eggs) {
		scanf("%d%d", &egg.first, &egg.second);
	}

	const int result = solve(eggs);

	printf("%d\n", result);

	return 0;
}