#include <iostream>

using namespace std;

void test_case(void) {
	long long N, K;
	cin >> N >> K;

	if (N <= K) {
		K = N - 1;
	}

	const long long result = 2 * N * (N + 1) - 2 * (N - K - 1) * (N - K);
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