#include <iostream>

using namespace std;

int main(void) {
	int T;
	cin >> T;

	while (T--) {
		long long N;
		cin >> N;

		if (N % 10) {
			cout << 0 << "\n";
		}
		else {
			cout << 1 << "\n";
		}
	}

	return 0;
}