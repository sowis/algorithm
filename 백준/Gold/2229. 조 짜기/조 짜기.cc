#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> skills;
vector<vector<int>> cache;

int solve(const int begin, const int end) {
	if (end - 1 <= begin) {
		return 0;
	}

	int& c = cache[begin][end];
	if (c != -1) {
		return c;
	}

	int max_diff = 0;
	int min_value = skills[begin];
	int max_value = skills[begin];
	int result = 0;
	for (int cut = begin; cut < end; ++cut) {
		min_value = min(min_value, skills[cut]);
		max_value = max(max_value, skills[cut]);
		max_diff = max(max_diff, max_value - min_value);
		result = max(result, max_diff + solve(cut + 1, end));
	}

	return c = result;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	skills = vector<int>(N);
	for (int& skill : skills) {
		cin >> skill;
	}

	cache = vector<vector<int>>(N + 1, vector<int>(N + 1, -1));
	const int result = solve(0, N);

	cout << result;

	return 0;
}