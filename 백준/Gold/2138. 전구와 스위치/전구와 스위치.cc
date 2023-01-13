#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N;

int solve(const string& source, const string& target) {
	string current = source;
	int result = 0;
	
	for (int i = 1; i < N - 1; ++i) {
		if (current[i - 1] != target[i - 1]) {
			++result;
			for (int k = i - 1; k <= i + 1; ++k) {
				current[k] = (current[k] == '0') ? '1' : '0';
			}
		}
	}

	if (current == target) {
		return result;
	}

	return 987654321;
}

int main(void) {
	cin >> N;

	string source, target;
	cin >> source;
	cin >> target;

	int result = 1987654321;
	result = min(result, solve(source, target));

	string current = source;
	current[0] = (current[0] == '0') ? '1' : '0';
	current[1] = (current[1] == '0') ? '1' : '0';
	result = min(result, solve(current, target) + 1);

	current = source;
	current[N - 2] = (current[N - 2] == '0') ? '1' : '0';
	current[N - 1] = (current[N - 1] == '0') ? '1' : '0';
	result = min(result, solve(current, target) + 1);

	current = source;
	current[0] = (current[0] == '0') ? '1' : '0';
	current[1] = (current[1] == '0') ? '1' : '0';
	current[N - 2] = (current[N - 2] == '0') ? '1' : '0';
	current[N - 1] = (current[N - 1] == '0') ? '1' : '0';
	result = min(result, solve(current, target) + 2);

	if (result >= 987654321) {
		cout << -1;
	}
	else {
		cout << result;
	}

	return 0;
}