#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int result = 0;

void solve(const int cur, const int idx, const vector<int> &v) {
	if (cur % 2) {
		if (result % 2) {
			result = max(result, cur);
		}
		else {
			result = cur;
		}
	}
	else {
		if (result % 2 == 0) {
			result = max(result, cur);
		}
	}

	for (int next = idx + 1; next < v.size(); ++next) {
		solve(cur * v[next], next, v);
	}
}

int main(void) {
	vector<int> v(3);
	for (int& n : v) {
		scanf("%d", &n);
	}

	for (int i = 0; i < v.size(); ++i) {
		solve(v[i], i, v);
	}
	
	printf("%d\n", result);

	return 0;
}