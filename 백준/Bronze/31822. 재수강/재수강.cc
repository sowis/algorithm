#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string target;
	cin >> target;

	int N;
	cin >> N;

	int result = 0;
	for (int i = 0; i < N; ++i) {
		string str;
		cin >> str;

		bool ok = true;
		for (int k = 0; k < 5; ++k) {
			if (target[k] != str[k]) {
				ok = false;
				break;
			}
		}

		if (ok) {
			++result;
		}
	}

	cout << result << "\n";

	return 0;
}