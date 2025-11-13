#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	vector<int> values(N);
	for (int& value : values) {
		cin >> value;
	}

	int result = numeric_limits<int>::max();
	for (int i = 0; i < N; ++i) {
		const int target = -1 * values[i];
		const int right = (int)(lower_bound(values.begin(), values.end(), target) - values.begin());
		const int left = right - 1;

		if (right >= 0 && right < N && right != i) {
			if (abs(values[i] + values[right]) < abs(result)) {
				result = values[i] + values[right];
			}
		}

		if (0 <= left && left < N && left != i) {
			if (abs(values[i] + values[left]) < abs(result)) {
				result = values[i] + values[left];
			}
		}
	}

	cout << result;

	return 0;
}