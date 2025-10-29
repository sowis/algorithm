#include <iostream>

using namespace std;

int last_zero(int num, const int base) {
	int result = 0;
	while (num > 0) {
		if (num % base != 0) {
			break;
		}

		++result;
		num /= base;
	}

	return result;
}

void test_case(void) {
	int N;
	cin >> N;

	int result = 0;
	for (int base = 2; base <= N; ++base) {
		result += last_zero(N, base);
	}

	cout << result << "\n";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		test_case();
	}

	return 0;
}