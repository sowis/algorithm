#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long N;
vector<long long> A;
vector<long long> A_alter;
vector<long long> B;
vector<long long> B_alter;

int main(void) {
	cin >> N;

	A = vector<long long>(N);
	A_alter = vector<long long>(N);
	for (long long i = 0; i < N; ++i) {
		long long cur;
		cin >> cur;

		A[i] = cur;
		A_alter[i] = cur - i;
	}

	priority_queue<long long> q;
	for (long long i = 0; i < N; ++i) {
		q.push({ A_alter[i] });
		q.push({ A_alter[i] });
		q.pop();
		B_alter.push_back(q.top());
	}
	
	for (long long i = N - 2; i >= 0; --i) {
		B_alter[i] = min(B_alter[i], B_alter[i + 1]);
	}

	for (long long i = 0; i < N; ++i) {
		cout << B_alter[i] + i << "\n";
	}

	return 0;
}