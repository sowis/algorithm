#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		int count;
		cin >> count;

		char c;
		cin >> c;

		for (int k = 0; k < count; ++k) {
			cout << c;
		}

		cout << "\n";
	}

	return 0;
}