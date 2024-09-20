#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N, X, K;
	scanf("%d%d%d", &N, &X, &K);

	vector<int> v(N + 1, 0);
	v[X] = 1;
	for (int i = 0; i < K; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);

		swap(v[a], v[b]);
	}

	for (int i = 1; i <= N; ++i) {
		if (v[i]) {
			printf("%d\n", i);
			break;
		}
	}

	return 0;
}