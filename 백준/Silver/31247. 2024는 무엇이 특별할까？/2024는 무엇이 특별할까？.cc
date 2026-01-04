#include <iostream>

using namespace std;

inline void test_case(void) {
	long long N, K;
	cin >> N >> K;

	for (int i = 0; i < K; ++i) {
		N /= 2;

		if (N == 0) {
			break;
		}
	}

	cout << (N + 1) / 2 << "\n";
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