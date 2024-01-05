#include <iostream>

using namespace std;

int main(void) {
	int cur;
	cin >> cur;

	while (true) {
		char op;
		cin >> op;

		if (op == '=') {
			cout << cur << "\n";
			break;
		}

		int n;
		cin >> n;

		if (op == '+') {
			cur += n;
		}
		else if (op == '-') {
			cur -= n;
		}
		else if (op == '*') {
			cur *= n;
		}
		else if (op == '/') {
			cur /= n;
		}
	}

	return 0;
}