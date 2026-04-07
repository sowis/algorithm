#include <iostream>
#include <vector>

using namespace std;

int N, Q;
vector<int> arr;
int arr_begin = 0;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> Q;
	arr = vector<int>(N);
	
	for (int& number : arr) {
		cin >> number;
	}

	while (Q--) {
		int op;
		cin >> op;

		if (op == 1) {
			int i, x;
			cin >> i >> x;

			arr[(arr_begin + i - 1 + N) % N] += x;
		}
		else if (op == 2) {
			int s;
			cin >> s;

			arr_begin -= s;
			arr_begin += N;
			arr_begin %= N;
		}
		else if (op == 3) {
			int s;
			cin >> s;

			arr_begin += s;
			arr_begin %= N;
		}
	}

	for (int offset = 0; offset < N; ++offset) {
		cout << arr[(arr_begin + offset) % N] << " ";
	}

	return 0;
}