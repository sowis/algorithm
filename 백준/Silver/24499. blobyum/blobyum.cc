#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, K;
	cin >> N >> K;

	vector<int> arr(N);
	for (int& num : arr) {
		cin >> num;
	}

	for (int i = 0; i < N; ++i) {
		arr.push_back(arr[i]);
	}

	int current_sum = 0;
	for (int i = 0; i < K; ++i) {
		current_sum += arr[i];
	}

	int max_sum = current_sum;
	int left = 0;
	int right = K;

	while (left < N) {
		current_sum -= arr[left];
		++left;
		current_sum += arr[right];
		++right;

		max_sum = max(max_sum, current_sum);
	}

	cout << max_sum;

	return 0;
}