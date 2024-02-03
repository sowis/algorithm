#include <iostream>
#include <string>

using namespace std;

int S, P;
string str;
int min_target[4];
int current[4];

bool is_ok(void) {
	for (int i = 0; i < 4; ++i) {
		if (current[i] < min_target[i]) {
			return false;
		}
	}

	return true;
}

int main(void) {
	cin >> S >> P;
	cin >> str;

	for (int i = 0; i < 4; ++i) {
		cin >> min_target[i];
	}

	for (int i = 0; i < P; ++i) {
		if (str[i] == 'A') {
			++current[0];
		}
		else if (str[i] == 'C') {
			++current[1];
		}
		else if (str[i] == 'G') {
			++current[2];
		}
		else {
			++current[3];
		}
	}
	
	int result = 0;
	if (is_ok()) {
		++result;
	}

	for (int i = P; i < S; ++i) {
		if (str[i] == 'A') {
			++current[0];
		}
		else if (str[i] == 'C') {
			++current[1];
		}
		else if (str[i] == 'G') {
			++current[2];
		}
		else {
			++current[3];
		}

		if (str[i - P] == 'A') {
			--current[0];
		}
		else if (str[i - P] == 'C') {
			--current[1];
		}
		else if (str[i - P] == 'G') {
			--current[2];
		}
		else {
			--current[3];
		}

		if (is_ok()) {
			++result;
		}
	}

	cout << result << "\n";

	return 0;
}