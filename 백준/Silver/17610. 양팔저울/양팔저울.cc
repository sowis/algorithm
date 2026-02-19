#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int K;
vector<int> G;
unordered_set<int> possibles;

void solve(const int idx = 0, const int current = 0) {
	possibles.insert(current);

	if (idx == K) {
		return;
	}

	solve(idx + 1, current);
	solve(idx + 1, current + G[idx]);
	solve(idx + 1, current - G[idx]);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> K;
	G = vector<int>(K);
	int weight_sum = 0;
	for (int& g : G) {
		cin >> g;
		weight_sum += g;
	}

	solve();

	int result = 0;
	for (int target = 1; target <= weight_sum; ++target) {
		if (possibles.find(target) == possibles.end()) {
			++result;
		}
	}

	cout << result;

	return 0;
}