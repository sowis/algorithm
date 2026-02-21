#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int M;
	cin >> M;

	vector<int> numbers(M);
	for (int& num : numbers) {
		cin >> num;
	}

	int max_up_len = 1;
	int len = 1;
	
	for (int i = 1; i < M; ++i) {
		if (numbers[i] > numbers[i - 1]) {
			++len;
		}
		else if (numbers[i] < numbers[i - 1]) {
			len = 1;
		}

		max_up_len = max(max_up_len, len);
	}

	int max_down_len = 1;
	len = 1;

	for (int i = 1; i < M; ++i) {
		if (numbers[i] < numbers[i - 1]) {
			++len;
		}
		else if (numbers[i] > numbers[i - 1]) {
			len = 1;
		}

		max_down_len = max(max_down_len, len);
	}

	cout << max(max_up_len, max_down_len);

	return 0;
}