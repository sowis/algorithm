#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int N;

int main(void) {
	cin >> N;

	vector<int> arr(N);
	for (int& num : arr) {
		cin >> num;
	}

	sort(arr.begin(), arr.end());

	int result = numeric_limits<int>::max();
	for (int outer_left_index = 0; outer_left_index < N; ++outer_left_index) {
		for (int outer_right_index = outer_left_index + 3; outer_right_index < N; ++outer_right_index) {
			const int outer_sum = arr[outer_left_index] + arr[outer_right_index];

			int L = outer_left_index + 1;
			int R = outer_right_index - 1;

			while (L < R) {
				const int inner_sum = arr[L] + arr[R];
				result = min(result, abs(outer_sum - inner_sum));

				if (inner_sum < outer_sum) {
					++L;
				}
				else {
					--R;
				}
			}
		}
	}

	cout << result;

	return 0;
}