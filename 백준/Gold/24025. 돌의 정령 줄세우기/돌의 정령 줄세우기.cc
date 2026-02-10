#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> A;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	A = vector<int>(N);
	for (int& a : A) {
		cin >> a;
	}

	if (A[N - 1] < 0) {
		cout << -1;
		return 0;
	}

	vector<int> result(N);
	for (int i = 0; i < N; ++i) {
		result[i] = N - i;
	}

	int minus_begin = -1;
	for (int i = 0; i < N; ++i) {
		if (A[i] < 0) {
			if (minus_begin == -1) {
				minus_begin = i;
			}
		}
		else {
			if (minus_begin != -1) {
				reverse(&result[minus_begin], &result[i + 1]);
				minus_begin = -1;
			}
		}
	}

	for (const int r : result) {
		cout << r << " ";
	}

	return 0;
}