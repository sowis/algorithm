#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(void) {
	string line;
	getline(cin, line);

	istringstream ss(line);
	int T;
	ss >> T;

	for (int i = 0; i < T; ++i) {
		getline(cin, line);

		ss = istringstream(line);
		double num;
		ss >> num;

		char op;
		while (ss >> op) {
			switch (op) {
			case '@':
				num *= 3;
				break;
			case '%':
				num += 5;
				break;
			case '#':
				num -= 7;
				break;
			}
		}

		cout << fixed;
		cout.precision(2);
		cout << num << "\n";
	}

	return 0;
}