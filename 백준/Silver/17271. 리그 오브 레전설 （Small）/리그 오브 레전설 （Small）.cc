#include <iostream>
#include <vector>

using namespace std;

constexpr int DIV = 1000000007;

int N, M;
int cache[10001];

int solve(const int remain_time) {
	int& c = cache[remain_time];
	if (c != -1) {
		return c;
	}

	if (remain_time == 0) {
		return c = 1;
	}

	int result = solve(remain_time - 1);
	result %= DIV;

	if (remain_time >= M) {
		result += solve(remain_time - M);
		result %= DIV;
	}
	
	return c = result;
}

int main(void) {
	cin >> N >> M;

	for (int i = 0; i < 10001; ++i) {
		cache[i] = -1;
	}

	cout << solve(N);

	return 0;
}