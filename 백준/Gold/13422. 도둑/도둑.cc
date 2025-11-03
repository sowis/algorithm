#include <iostream>
#include <vector>

using namespace std;

void test_case(void) {
	int N, M, K;
	cin >> N >> M >> K;

	vector<int> money(N);
	for (int& num : money) {
		cin >> num;
	}

	int money_sum = 0;
	int left = 0;
	int right = M;
	int result = 0;

	for (int i = 0; i < M; ++i) {
		money_sum += money[i];
	}

	if (money_sum < K) {
		++result;
	}

	if (N == M) {
		cout << result << "\n";
		return;
	}

	right %= N;

	for (int i = 1; i < N; ++i) {
		money_sum -= money[left];
		left = (left + 1) % N;
		money_sum += money[right];
		right = (right + 1) % N;

		if (money_sum < K) {
			++result;
		}
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