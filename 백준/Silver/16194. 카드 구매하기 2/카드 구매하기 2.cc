#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

vector<int> pi;
vector<int> cache;

int solve(const int remain) {
	int& c = cache[remain];
	if (c != -1) {
		return c;
	}

	c = pi[remain];
	for (int i = 1; i < remain; ++i) {
		c = min(c, solve(i) + solve(remain - i));
	}

	return c;
}

int main(void) {
	int N;
	scanf("%d", &N);

	cache = vector<int>(N + 1, -1);
	pi = vector<int>(N + 1);
	for (int i = 1; i <= N; ++i) {
		scanf("%d", &pi[i]);
	}

	cache[0] = 0;
	cache[1] = pi[1];

	const int result = solve(N);
	printf("%d\n", result);

	return 0;
}