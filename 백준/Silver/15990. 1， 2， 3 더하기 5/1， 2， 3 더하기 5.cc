#include <cstdio>
#include <vector>

using namespace std;

constexpr int DIV = 1000000009;

vector<vector<int>> cache(1000001, vector<int>(5, -1));

int solve(const int number, const int last = 4) {
	int& c = cache[number][last];
	if (c != -1) {
		return c;
	}

	if (number == 0) {
		return c = 1;
	}

	int result = 0;
	for (int next = 1; next <= 3; ++next) {
		if (last == next) {
			continue;
		}

		if (number < next) {
			continue;
		}

		result += solve(number - next, next);
		result %= DIV;
	}

	return c = result;
}

int main(void) {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		int N;
		scanf("%d", &N);

		const int result = solve(N);
		printf("%d\n", result);
	}

	return 0;
}