#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int N;
vector<long long> arr;

long long make_stair(const int target_index_1, const int target_index_2) {
	long long result = 0;
	const long long diff = (arr[target_index_2] - arr[target_index_1]) / (target_index_2 - target_index_1);
	if (diff * (target_index_2 - target_index_1) != (arr[target_index_2] - arr[target_index_1])) {
		return numeric_limits<long long>::max();
	}

	long long target_num = arr[target_index_1] - (target_index_1 * diff);
	for (int i = 0; i < N; ++i) {
		if (arr[i] != target_num) {
			++result;
		}

		target_num += diff;
	}

	return result;
}

long long make_same(const int target_index) {
	long long result = 0;
	for (const long long num : arr) {
		if (num != arr[target_index]) {
			++result;
		}
	}

	return result;
}

int main(void) {
	cin >> N;

	arr = vector<long long>(N);
	for (long long& num : arr) {
		cin >> num;
	}

	long long result = numeric_limits<long long>::max();
	for (int i = 0; i < N; ++i) {
		result = min(result, make_same(i));

		for (int k = i + 1; k < N; ++k) {
			result = min(result, make_stair(i, k));
		}
	}

	cout << result;

	return 0;
}