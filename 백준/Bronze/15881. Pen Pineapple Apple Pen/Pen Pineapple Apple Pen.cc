#include <iostream>
#include <string>

using namespace std;

bool pPAp(const string& str, int begin_idx) {
	const static string target = "pPAp";
	for (int i = 0; i < 4; ++i) {
		if (str[begin_idx + i] != target[i]) {
			return false;
		}
	}

	return true;
}

int main(void) {
	int N;
	cin >> N;

	string input;
	cin >> input;

	int result = 0;
	for (int i = 0; i < N - 3; ++i) {
		if (pPAp(input, i) == false) {
			continue;
		}

		++result;
		i += 3;
	}

	cout << result;

	return 0;
}