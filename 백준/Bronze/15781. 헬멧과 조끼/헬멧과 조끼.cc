#include <cstdio>
#include <algorithm>

using namespace std;

int main(void) {
	int N, M;
	scanf("%d%d", &N, &M);

	int d1 = 0, d2 = 0;
	for (int i = 0; i < N; ++i) {
		int d;
		scanf("%d", &d);

		d1 = max(d1, d);
	}

	for (int i = 0; i < M; ++i) {
		int d;
		scanf("%d", &d);

		d2 = max(d2, d);
	}

	printf("%d\n", d1 + d2);

	return 0;
}