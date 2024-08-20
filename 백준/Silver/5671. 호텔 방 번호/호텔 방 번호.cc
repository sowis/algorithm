#include <iostream>
#include <vector>

using namespace std;

bool is_ok(int num) {
	vector<bool> check(10, false);
	while (num > 0) {
		if (check[num % 10]) {
			return false;
		}

		check[num % 10] = true;
		num /= 10;
	}

	return true;
}

int main(void) {
	int N, M;
	while (cin >> N) {
		cin >> M;

		int result = 0;
		for (int i = N; i <= M; ++i) {
			if (is_ok(i)) {
				++result;
			}
		}

		cout << result << "\n";
	}

	return 0;
}