#include <iostream>
#include <string>

using namespace std;

int speak(const string& str, const int idx) {
	if (str[idx] == 'p') {
		if (idx + 1 >= str.size()) {
			return -1;
		}

		if (str[idx + 1] == 'i') {
			return idx + 2;
		}
		else {
			return -1;
		}
	}
	else if (str[idx] == 'k') {
		if (idx + 1 >= str.size()) {
			return -1;
		}

		if (str[idx + 1] == 'a') {
			return idx + 2;
		}
		else {
			return -1;
		}
	}
	else if (str[idx] == 'c') {
		if (idx + 2 >= str.size()) {
			return -1;
		}

		if (str[idx + 1] == 'h' && str[idx + 2] == 'u') {
			return idx + 3;
		}
		else {
			return -1;
		}
	}
	else {
		return -1;
	}
}

int main(void) {
	string input;
	cin >> input;

	int idx = 0;
	while (true) {
		if (idx == input.size()) {
			cout << "YES\n";
			return 0;
		}

		idx = speak(input, idx);

		if (idx == -1) {
			cout << "NO\n";
			return 0;
		}
	}

	return 0;
}