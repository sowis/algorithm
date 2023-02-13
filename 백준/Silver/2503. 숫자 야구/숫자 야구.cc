#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<bool> candidates(1000, true);

bool available(const string& str) {
	for (int i = 0; i < 3; ++i) {
		if (str[i] == '0') {
			return false;
		}
	}

	for (int i = 0; i < 3; ++i) {
		for (int k = 0; k < 3; ++k) {
			if (i == k) {
				continue;
			}

			if (str[i] == str[k]) {
				return false;
			}
		}
	}

	return true;
}

pair<int, int> baseball(const string& target, const string& source) {
	pair<int, int> result{ 0, 0 };

	for (int i = 0; i < target.size(); ++i) {
		if (target[i] == source[i]) {
			++result.first;
		}
	}

	for (int i = 0; i < 3; ++i) {
		for (int k = 0; k < 3; ++k) {
			if (i == k) {
				continue;
			}

			if (target[i] == source[k]) {
				++result.second;
			}
		}
	}

	return result;
}

int main(void) {
	for (int i = 0; i < 1000; ++i) {
		const string target_string = string(3 - to_string(i).size(), '0').append(to_string(i));
		if (available(target_string) == false) {
			candidates[i] = false;
		}
	}

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		string number;
		cin >> number;

		int strike, ball;
		cin >> strike >> ball;

		for (int k = 1; k < 1000; ++k) {
			const string target_string = string(3 - to_string(k).size(), '0').append(to_string(k));
			const pair<int, int> baseball_result = baseball(target_string, number);
			if (baseball_result.first != strike || baseball_result.second != ball) {
				candidates[k] = false;
			}
		}
	}

	int result = 0;
	for (int i = 0; i < 1000; ++i) {
		if (candidates[i]) {
			++result;
		}
	}

	cout << result << "\n";

	return 0;
}