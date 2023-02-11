#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		int r, e, c;
		cin >> r >> e >> c;

		if (e == r + c) {
			cout << "does not matter\n";
		}
		else if (e > r + c) {
			cout << "advertise\n";
		}
		else {
			cout << "do not advertise\n";
		}
	}

	return 0;
}