#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void) {
	int N, M;
	scanf("%d%d", &N, &M);

	vector<int> pos(M);
	for (int& p : pos) {
		scanf("%d", &p);
	}

	sort(pos.begin(), pos.end());

	int result = max(pos[0], N - pos[M - 1]);
	for (int i = 1; i < M; ++i) {
		result = max(result, (int)ceil((double)(pos[i] - pos[i - 1]) / 2));
	}

	printf("%d\n", result);

	return 0;
}