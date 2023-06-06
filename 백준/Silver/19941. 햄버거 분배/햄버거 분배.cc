#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N, K;
	cin >> N >> K;

	string arr;
	cin >> arr;

	int result = 0;
	vector<bool> burger(N, false);
	for (int i = 0; i < N; ++i) {
		if (arr[i] == 'H') {
			burger[i] = true;
		}
	}

	for (int i = 0; i < N; ++i) {
		if (arr[i] == 'H') {
			continue;
		}

		for (int target = max(0, i - K); target < min(N, i + K + 1); ++target) {
			if (burger[target] == false) {
				continue;
			}

			burger[target] = false;
			++result;
			break;
		}
	}

	cout << result << "\n";

	return 0;
}