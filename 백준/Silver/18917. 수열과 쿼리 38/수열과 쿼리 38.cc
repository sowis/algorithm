#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int M;
	cin >> M;

	long long cur_sum = 0;
	int cur_xor = 0;
	for (int i = 0; i < M; ++i) {
		int op;
		cin >> op;

		if (op == 1) {
			int num;
			cin >> num;

			cur_sum += num;
			cur_xor ^= num;
		}
		else if (op == 2) {
			int num;
			cin >> num;

			cur_sum -= num;
			cur_xor ^= num;
		}
		else if (op == 3) {
			cout << cur_sum << "\n";
		}
		else if (op == 4) {
			cout << cur_xor << "\n";
		}
	}

	return 0;
}