#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long N, B, C;
long long a, b, c; // 각각 1비용, 2비용, 3비용

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> B >> C;

	a = B;
	b = B + C;
	c = B + 2 * C;

	vector<long long> arr(N);
	for (long long& a : arr) {
		cin >> a;
	}

	if (B <= C) {
		long long result = 0;
		for (const long long count : arr) {
			result += B * count;
		}

		cout << result;
		return 0;
	}

	long long result = 0;
	for (int i = 0; i < N; ++i) {
		if (i + 2 < N) {
			if (arr[i + 1] > arr[i + 2]) {
				const long long count = min(arr[i], arr[i + 1] - arr[i + 2]);
				result += b * count;
				arr[i] -= count;
				arr[i + 1] -= count;
			}

			const long long count = min(arr[i], min(arr[i + 1], arr[i + 2]));
			result += c * count;
			arr[i] -= count;
			arr[i + 1] -= count;
			arr[i + 2] -= count;
		}

		if (i + 1 < N) {
			const long long count = min(arr[i], arr[i + 1]);
			result += b * count;
			arr[i] -= count;
			arr[i + 1] -= count;
		}

		result += a * arr[i];
		arr[i] = 0;
	}

	cout << result;

	return 0;
}