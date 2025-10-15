#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void test_case(void) {
	int L, R;
	cin >> L >> R;

	const int pair = min(L, R);
	const int result = pair * (pair + 1) / 2;
	cout << result << "\n";
}

int main(void) {
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		cout << "Case #" << i + 1 << ": ";
		test_case();
	}

	return 0;
}