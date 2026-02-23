#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long N, T;
	cin >> N >> T;

	long long result = 0;
	vector<long long> P(N);
	for (long long& p : P) {
		long long w;
		cin >> w >> p;
		result += w;
	}

	sort(P.begin(), P.end());

	for (int i = 0; i < N; ++i) {
		result += P[i] * (T - N + i);
	}

	cout << result;

	return 0;
}