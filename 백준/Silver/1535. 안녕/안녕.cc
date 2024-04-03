#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int L[20];
int J[20];
int result = 0;

void backtracking(const int idx = 0, const int hp = 100, const int happy = 0) {
	if (hp <= 0) {
		return;
	}

	result = max(result, happy);

	if (idx == N) {
		return;
	}

	backtracking(idx + 1, hp - L[idx], happy + J[idx]);
	backtracking(idx + 1, hp, happy);
}

int main(void) {
	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		scanf("%d", &L[i]);
	}

	for (int i = 0; i < N; ++i) {
		scanf("%d", &J[i]);
	}

	backtracking();

	printf("%d\n", result);

	return 0;
}