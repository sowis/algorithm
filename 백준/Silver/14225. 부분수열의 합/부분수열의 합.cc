#include <cstdio>
#include <vector>
#include <unordered_set>

using namespace std;

int N;
vector<int> arr;
unordered_set<int> s;

void solve(const int idx, const int cur) {
	if (idx == N) {
		s.insert(cur);
		return;
	}

	solve(idx + 1, cur + arr[idx]);
	solve(idx + 1, cur);
}

int main(void) {
	scanf("%d", &N);

	arr = vector<int>(N);
	for (int& n : arr) {
		scanf("%d", &n);
	}

	solve(0, 0);

	for (int num = 1; ; ++num) {
		if (s.find(num) == s.end()) {
			printf("%d\n", num);
			break;
		}
	}

	return 0;
}