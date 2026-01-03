#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	vector<int> numbers(N + 1, -1987654321);
	int decrease_count = 0;
	int decrease_idx = -1;
	for (int i = 1; i <= N; ++i) {
		cin >> numbers[i];

		if (numbers[i - 1] > numbers[i]) {
			++decrease_count;
			decrease_idx = i;
		}
	}

	numbers.push_back(1987654321);

	if (decrease_count == 0) {
		cout << N;
	}
	else if (decrease_count >= 2) {
		cout << 0;
	}
	else {
		int result = 0;
		if (numbers[decrease_idx - 1] <= numbers[decrease_idx + 1]) {
			++result;
		}

		if (numbers[decrease_idx - 2] <= numbers[decrease_idx]) {
			++result;
		}

		cout << result;
	}

	return 0;
}