#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int K;
int sz;
vector<int> inputs;
vector<vector<int>> tree;

void solve(const int begin, const int end, const int lv = 0) {
	const int cur = (begin + end) / 2;
	tree[lv].push_back(inputs[cur]);

	if (lv == K - 1) {
		return;
	}

	solve(begin, cur - 1, lv + 1);
	solve(cur + 1, end, lv + 1);
}

int main(void) {
	scanf("%d", &K);

	sz = (int)pow(2, K) - 1;
	tree = vector<vector<int>>(K);

	for (int i = 0; i < sz; ++i) {
		int input;
		scanf("%d", &input);
		inputs.push_back(input);
	}

	solve(0, sz);

	for (const vector<int>& line : tree) {
		for (const int node : line) {
			printf("%d ", node);
		}

		printf("\n");
	}

	return 0;
}