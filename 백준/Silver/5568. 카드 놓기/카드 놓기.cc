#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

unordered_set<string> result;

void dfs(const string& current, const int remain, const vector<string> &numbers, vector<bool>& used) {
	if (remain == 0) {
		result.insert(current);
		return;
	}

	for (int i = 0; i < used.size(); ++i) {
		if (used[i]) {
			continue;
		}

		used[i] = true;
		dfs(current + numbers[i], remain - 1, numbers, used);
		used[i] = false;
	}
}

int main(void) {
	int N, K;
	cin >> N >> K;

	vector<string> numbers(N);
	for (string& number : numbers) {
		cin >> number;
	}

	vector<bool> used(N, false);
	dfs("", K, numbers, used);

	cout << result.size();

	return 0;
}