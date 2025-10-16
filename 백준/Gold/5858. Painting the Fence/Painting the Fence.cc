#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	long long N;
	cin >> N;

	long long cur = 0;
	vector<pair<long long, long long>> draws;
	for (long long i = 0; i < N; ++i) {
		long long dist;
		char op;

		cin >> dist >> op;

		long long left, right;

		if (op == 'L') {
			left = cur - dist;
			right = cur;
			cur -= dist;
		}
		else {
			left = cur;
			right = cur + dist;
			cur += dist;
		}

		draws.push_back({ left, right });
	}

	sort(draws.begin(), draws.end());

	long long cur_left = -1987654321;
	long long cur_right = -1987654321;
	long long result = 0;

	for (const pair<long long, long long>& p : draws) {
		const long long left = p.first;
		const long long right = p.second;

		if (right <= cur_left) {
			continue;
		}

		if (cur_right <= left) {
			cur_left = left;
			cur_right = right;
			continue;
		}

		const long long overlap_left = max(cur_left, left);
		const long long overlap_right = min(cur_right, right);

		result += overlap_right - overlap_left;

		cur_left = overlap_right;
		cur_right = max(cur_right, right);
	}

	cout << result;

	return 0;
}