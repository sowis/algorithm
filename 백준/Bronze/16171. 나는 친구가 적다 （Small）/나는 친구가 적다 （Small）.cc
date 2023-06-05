#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string S, K;
	cin >> S >> K;

	string digit_removed;
	for (const char c : S) {
		if ('0' <= c && c <= '9') {
			continue;
		}

		digit_removed += c;
	}

	if (digit_removed.find(K) == string::npos) {
		cout << 0 << "\n";
	}
	else {
		cout << 1 << "\n";
	}

	return 0;
}