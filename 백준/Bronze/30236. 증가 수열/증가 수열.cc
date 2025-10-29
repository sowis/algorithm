#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void test_case(void) {
	int N;
	cin >> N;

	vector<int> a(N);
	for (int& num : a) {
		cin >> num;
	}

	int bi = 0;
	for (int i = 0; i < N; ++i) {
		++bi;

		if (bi == a[i]) {
			++bi;
		}
	}

	cout << bi << "\n";
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