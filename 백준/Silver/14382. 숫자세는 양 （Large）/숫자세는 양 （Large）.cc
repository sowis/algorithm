#include <iostream>
#include <vector>

using namespace std;

bool v_insert(vector<bool>& check, long long num) { // num 의 각 자리수를 check 벡터에 체크하고, 0~9의 숫자가 전부 체크되어있으면 true, 아니면 false 반환
	while (num > 0) {
		check[num % 10] = true;
		num /= 10;
	}

	for (int i = 0; i < 10; ++i) {
		if (check[i] == false) {
			return false;
		}
	}

	return true;
}

void test_case(const int id) {
	long long N;
	cin >> N;

	cout << "Case #" << id << ": ";
	if (N == 0) {
		cout << "INSOMNIA\n";
		return;
	}

	long long cur = N;
	vector<bool> check(10, false);
	while (true) {
		if (v_insert(check, cur)) {
			cout << cur << "\n";
			return;
		}

		cur += N;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		test_case(i + 1);
	}

	return 0;
}