#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

void create(const vector<int>& source, vector<int>& results, const int idx, const int remain, const int current) {
	if (remain == 0) {
		results.push_back(current);
		return;
	}

	if (idx + remain > source.size()) {
		return;
	}

	create(source, results, idx + 1, remain, current);
	create(source, results, idx + 1, remain - 1, current + source[idx]);
}

void test_case(void) {
	int n, m, k;
	cin >> n >> m >> k;

	vector<int> bob_numbers(n);
	for (int& n : bob_numbers) {
		cin >> n;
	}

	vector<int> alice_numbers(m);
	for (int& n : alice_numbers) {
		cin >> n;
	}

	sort(bob_numbers.begin(), bob_numbers.end());
	sort(alice_numbers.begin(), alice_numbers.end());

	int minmax[2][2] = { 0 };
	for (int i = 0; i < k; ++i) {
		minmax[0][0] += bob_numbers[i];
		minmax[0][1] += bob_numbers[n - 1 - i];
		minmax[1][0] += alice_numbers[i];
		minmax[1][1] += alice_numbers[m - 1 - i];
	}

	int max_result = 0;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			max_result = max(max_result, abs(minmax[0][i] - minmax[1][j]));
		}
	}

	int min_result = numeric_limits<int>::max();
	vector<int> bob_sums, alice_sums;
	create(bob_numbers, bob_sums, 0, k, 0);
	create(alice_numbers, alice_sums, 0, k, 0);

	sort(bob_sums.begin(), bob_sums.end());
	sort(alice_sums.begin(), alice_sums.end());

	for (const int bob : bob_sums) {
		const int idx = (int)(lower_bound(alice_sums.begin(), alice_sums.end(), bob) - alice_sums.begin());
		if (idx != alice_sums.size()) {
			min_result = min(min_result, abs(alice_sums[idx] - bob));
		}

		if (idx - 1 >= 0) {
			min_result = min(min_result, abs(alice_sums[idx - 1] - bob));
		}
	}

	cout << min_result << " " << max_result << "\n";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int T;
	cin >> T;

	while (T--) {
		test_case();
	}

	return 0;
}