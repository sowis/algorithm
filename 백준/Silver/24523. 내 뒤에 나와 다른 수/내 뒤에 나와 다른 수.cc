#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	vector<int> numbers(N);
	for (int& number : numbers) {
		cin >> number;
	}

	int left = 0;
	int right = 0;
	vector<int> results(N, -2);

	while (left < N) {
		while (right < N && numbers[left] == numbers[right]) {
			++right;
		}

		if (right == N) {
			break;
		}

		for (int i = left; i < right; ++i) {
			results[i] = right;
		}

		left = right;
	}

	for (const int result : results) {
		cout << result + 1 << " ";
	}

	return 0;
}