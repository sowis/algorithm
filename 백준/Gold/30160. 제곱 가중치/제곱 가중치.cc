#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int N;
	cin >> N;

	vector<int> A(N);
	for (int& a : A) {
		cin >> a;
	}

	vector<long long> psum(1);
	vector<long long> odd_psum(1);

	long long cur = 0;
	for (int i = 0; i < N; ++i) {
		cur += A[i];
		psum.push_back(cur);
	}

	cur = 0;
	for (int i = 0; i < N; ++i) {
		cur += (2 * i + 1) * A[i];
		odd_psum.push_back(cur);
	}

	long long result = 0;
	for (long long k = 1; k <= N; ++k) {
		result += (2 * k * psum[k]) - odd_psum[k];
		cout << result << " ";
	}

	return 0;
}