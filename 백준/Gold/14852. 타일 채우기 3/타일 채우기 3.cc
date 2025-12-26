#include <iostream>
#include <vector>

using namespace std;

constexpr long long DIV = 1000000007;

long long N;
vector<vector<long long>> cache;

int main(void) {
	cin >> N;

	cache = vector<vector<long long>>(N + 2, vector<long long>(3, 0));

	cache[0][0] = 1;
	for (int i = 0; i < N; ++i) {
		for (int op = 0; op < 3; ++op) {
			cache[i][op] %= DIV;
			if (op == 0) {
				cache[i + 1][0] += cache[i][op]; // 2x1
				cache[i][2] += cache[i][op]; // 1x1
				cache[i + 1][2] += cache[i][op]; // 1x2, 1x1
				cache[i + 2][0] += cache[i][op]; // 1x2, 1x2
			}
			else if (op == 1) {
				cache[i + 1][0] += cache[i][op]; // 1x1
				cache[i + 1][2] += cache[i][op]; // 1x2
			}
			else {
				cache[i + 1][0] += cache[i][op]; // 1x1
				cache[i + 1][1] += cache[i][op]; // 1x2
			}
		}
	}

	cout << cache[N][0] % DIV;

	return 0;
}