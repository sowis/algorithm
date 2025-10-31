#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	vector<int> arr(N);
	for (int& a : arr) {
		cin >> a;
	}

	long long result = 0;
	for (int i = 0; i < N; ++i) {
		if (i + 2 < N) {
			if (arr[i + 1] > arr[i + 2]) {
				const int count = min(arr[i], arr[i + 1] - arr[i + 2]);
				result += 5 * count;
				arr[i] -= count;
				arr[i + 1] -= count;
			}

			const int count = min(arr[i], min(arr[i + 1], arr[i + 2]));
			result += 7 * count;
			arr[i] -= count;
			arr[i + 1] -= count;
			arr[i + 2] -= count;
		}

		if (i + 1 < N) {
			const int count = min(arr[i], arr[i + 1]);
			result += 5 * count;
			arr[i] -= count;
			arr[i + 1] -= count;
		}

		result += 3 * arr[i];
		arr[i] = 0;
	}

	cout << result;

	return 0;
}