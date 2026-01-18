#include <iostream>
#include <vector>

using namespace std;

constexpr long long DIV = 1000000007;

vector<vector<long long>> cache;

long long solve(const int remain_1, const int remain_0) {
	if ((remain_1 < 0) || (remain_0 < 0)) {
		return 0;
	}

	long long& c = cache[remain_1][remain_0];
	if (c != -1) {
		return c;
	}

	if (remain_1 == 0 && remain_0 == 0) {
		return c = 1;
	}

	return c = (solve(remain_1, remain_0 - 3) + solve(remain_1 - 2, remain_0 - 1) * 3) % DIV;
}

int main(void) {
	int X, Y;
	cin >> X >> Y;

	cache = vector<vector<long long>>(X + 1, vector<long long>(Y + 1, -1));
	
	cout << solve(X, Y);

	return 0;
}