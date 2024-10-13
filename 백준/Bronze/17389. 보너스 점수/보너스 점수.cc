#include <iostream>

using namespace std;

int main(void) {
	int N;
	cin >> N;

	string input;
	cin >> input;

	long long result = 0;
	int bonus = 0;
	for (int i = 1; i <= N; ++i) {
		if (input[i - 1] == 'O') {
			result += i;
			result += bonus;
			++bonus;
		}
		else {
			bonus = 0;
		}
	}

	cout << result;

	return 0;
}