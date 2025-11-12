#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> down_numbers;

void solve(const long long cur) {
	down_numbers.push_back(cur);
	const long long last = cur % 10;
	for (int i = 0; i < last; ++i) {
		solve(cur * 10 + i);
	}
}

int main(void) {
	for (int i = 0; i < 10; ++i) {
		solve(i);
	}

	sort(down_numbers.begin(), down_numbers.end());

	int N;
	cin >> N;

	--N;
	if (N >= down_numbers.size()) {
		cout << -1;
		return 0;
	}

	cout << down_numbers[N];

	return 0;
}