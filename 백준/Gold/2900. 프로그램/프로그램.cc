#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

long long N, K, Q;
vector<long long> a;
unordered_map<long long, long long> jump_counts;
vector<long long> psum;

void something(const long long jump, const long long count) {
	long long i = 0;
	while (i < N) {
		a[i] = a[i] + count;
		i = i + jump;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> K;
	for (long long i = 0; i < K; ++i) {
		long long x;
		cin >> x;

		++jump_counts[x];
	}

	a = vector<long long>(N + 1, 0);
	for (const pair<long long, long long>& p : jump_counts) {
		const long long jump = p.first;
		const long long count = p.second;

		something(jump, count);
	}

	psum = vector<long long>(N + 1, 0);
	long long current_sum = 0;
	for (long long i = 0; i <= N; ++i) {
		psum[i] = current_sum;
		current_sum += a[i];
	}

	cin >> Q;
	
	while (Q--) {
		long long L, R;
		cin >> L >> R;

		cout << psum[R + 1] - psum[L] << "\n";
	}

	return 0;
}