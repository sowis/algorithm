#include <iostream>
#include <vector>

using namespace std;

void test_case(void) {
	int N;
	cin >> N;

	vector<vector<bool>> cache(N + 1, vector<bool>(7, false));
	cache[0][1] = true;

	for (int i = 0; i < N; ++i) {
		for (int k = 0; k < 2; ++k) {
			char op;
			int value;

			cin >> op >> value;

			for (int j = 0; j < 7; ++j) {
				if (cache[i][j] == false) {
					continue;
				}

				if (op == '+') {
					cache[i + 1][(j + value) % 7] = true;
				}
				else {
					cache[i + 1][(j * value) % 7] = true;
				}
			}
		}
	}

	if (cache[N][0]) {
		cout << "LUCKY\n";
	}
	else {
		cout << "UNLUCKY\n";
	}
}

int main(void) {
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		test_case();
	}

	return 0;
}