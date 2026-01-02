#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	vector<long long> B(N);
	for (long long& b : B) {
		cin >> b;
	}

	vector<long long> A{ B[0] };
	long long a_psum = A[0];

	if ((A.back() < 1) || (1000000000 < A.back())) {
		cout << -1;
		return 0;
	}

	for (int i = 1; i < N; ++i) {
		if ((B[i] + 1) * i < a_psum) {
			A.push_back(B[i] + 1);
		}
		else if (B[i] * i >= a_psum) {
			A.push_back(B[i]);
		}
		else {
			cout << -1;
			return 0;
		}

		if ((A.back() < 1) || (1000000000 < A.back())) {
			cout << -1;
			return 0;
		}

		a_psum += A.back();
	}

	for (const long long a : A) {
		cout << a << " ";
	}

	return 0;
}