#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int N;
	cin >> N;

	string input;
	cin >> input;

	int len = 1;
	char cur = -1;
	for (const char c : input) {
		if (c == cur - 1 || c == cur + 1) {
			++len;
		}
		else {
			len = 1;
		}

		cur = c;

		if (len == 5) {
			cout << "YES\n";
			return 0;
		}
	}

	cout << "NO\n";

	return 0;
}