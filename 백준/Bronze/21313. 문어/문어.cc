#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	if (N % 2) {
		int cur = 1; 
		for (int i = 0; i < N - 1; ++i) {
			cout << cur << " ";

			if (cur == 1) {
				cur = 2;
			}
			else {
				cur = 1;
			}
		}

		cout << 3;
	}
	else {
		int cur = 1;
		for (int i = 0; i < N; ++i) {
			cout << cur << " ";

			if (cur == 1) {
				cur = 2;
			}
			else {
				cur = 1;
			}
		}
	}

	return 0;
}