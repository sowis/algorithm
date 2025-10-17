#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> ingredients[101];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; ++i) {
		int x, y, k;
		cin >> x >> y >> k;
		
		ingredients[x].push_back({ y, k });
	}

	vector<int> results(N + 1, 0);
	results[N] = 1;

	bool changed = false;
	do {
		changed = false;
		for (int target = 1; target <= N; ++target) {
			if (ingredients[target].size() == 0 || results[target] == 0) {
				continue;
			}

			for (const pair<int, int>& ingredient : ingredients[target]) {
				results[ingredient.first] += (results[target] * ingredient.second);
			}

			changed = true;
			results[target] = 0;
		}
	} while (changed == true);

	for (int i = 1; i <= N; ++i) {
		if (results[i] > 0) {
			cout << i << " " << results[i] << "\n";
		}
	}

	return 0;
}