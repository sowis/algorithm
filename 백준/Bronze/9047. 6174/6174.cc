#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int get_min_max(int num, const bool max) {
	vector<int> v(4);
	for (int i = 0; i < 4; ++i) {
		v[i] = num % 10;
		num /= 10;
	}

	if (max) {
		sort(v.begin(), v.end());
	}
	else {
		sort(v.begin(), v.end(), greater<int>());
	}

	int result = 0;
	int mul = 1;
	for (const int n : v) {
		result += n * mul;
		mul *= 10;
	}

	return result;
}

int solve(const int num) {
	int cur = num;
	int result = 0;

	while (cur != 6174) {
		cur = abs(get_min_max(cur, true) - get_min_max(cur, false));
		++result;
	}

	return result;
}

int main(void) {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		int num;
		scanf("%d", &num);

		const int result = solve(num);
		printf("%d\n", result);
	}

	return 0;
}