#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr long long EMPTY = -1;

int N, B;
vector<long long> bubbles;
vector<vector<long long>> cache;

long long solve(const int sz, const int bucket) {
	long long& c = cache[sz][bucket];
	if (c != EMPTY) {
		return c;
	}

	if (sz <= 1) {
		return c = 0;
	}

	if (bucket == 1) {
		return c = (bubbles[sz - 1] - bubbles[0]) * (bubbles[sz - 1] - bubbles[0]);
	}

	long long result = solve(sz, bucket - 1);
	for (int mid = 0; mid < sz; ++mid) {
		result = min(result, solve(mid, bucket - 1) + (bubbles[sz - 1] - bubbles[mid]) * (bubbles[sz - 1] - bubbles[mid]));
	}
	
	return c = result;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> B;

	bubbles = vector<long long>(N);
	cache = vector<vector<long long>>(N + 1, vector<long long>(N + 1, EMPTY));

	for (long long& bubble : bubbles) {
		cin >> bubble;
	}

	sort(bubbles.begin(), bubbles.end());

	cout << solve(N, B);

	return 0;
}