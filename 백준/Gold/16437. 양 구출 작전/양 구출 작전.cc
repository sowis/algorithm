#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> sheeps;
vector<long long> wolves;
vector<long long> edges[123459];

long long save_sheep(const long long cur, vector<bool> &visit) {
	visit[cur] = true;
	
	long long result = sheeps[cur] - wolves[cur];
	for (const long long next : edges[cur]) {
		if (visit[next]) {
			continue;
		}

		result += save_sheep(next, visit);
	}

	result = max(result, 0LL);
	return result;
}

int main(void) {
	long long N;
	cin >> N;

	sheeps = vector<long long>(N + 1, 0);
	wolves = vector<long long>(N + 1, 0);

	for (long long i = 2; i <= N; ++i) {
		char t;
		long long a, p;
		cin >> t >> a >> p;

		if (t == 'S') {
			sheeps[i] += a;
		}
		else {
			wolves[i] += a;
		}

		edges[i].push_back(p);
		edges[p].push_back(i);
	}

	vector<bool> visit(N + 1, false);
	const long long result = save_sheep(1, visit);

	cout << result;

	return 0;
}