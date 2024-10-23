#include <cstdio>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		int a, b, x;
		scanf("%d%d%d", &a, &b, &x);

		const int w = a * (x - 1) + b;
		printf("%d\n", w);
	}

	return 0;
}