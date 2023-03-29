#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N, M;
	scanf("%d%d", &N, &M);

	vector<int> balls(N + 1);
	for (int i = 0; i < N + 1; ++i) {
		balls[i] = i;
	}

	for (int i = 0; i < M; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		swap(balls[a], balls[b]);
	}

	for (int i = 1; i <= N; ++i) {
		printf("%d ", balls[i]);
	}

	return 0;
}