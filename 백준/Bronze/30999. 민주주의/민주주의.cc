#include <string>
#include <iostream>

using namespace std;

int main(void) {
	int N, M;
	cin >> N >> M;

	int result = 0;
	for (int i = 0; i < N; ++i) {
		string input;
		int ok_count = 0;

		cin >> input;
		for (const char c : input) {
			if (c == 'O') {
				++ok_count;
			}
		}

		if (ok_count > M / 2) {
			++result;
		}
	}

	cout << result << "\n";

	return 0;
}