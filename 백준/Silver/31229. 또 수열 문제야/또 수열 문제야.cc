#include <iostream>

using namespace std;

int main(void) {
	int N;
	cin >> N;

	for (long long i = 1; i <= N; ++i) {
		cout << 2 * i - 1 << " ";
	}

	return 0;
}