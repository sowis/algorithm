#include <cstdio>

using namespace std;

int main(void) {
	int a = 100, b = 100;

	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		int c, d;
		scanf("%d%d", &c, &d);
		if (c > d) {
			b -= c;
		}
		else if (c < d) {
			a -= d;
		}
	}

	printf("%d\n%d\n", a, b);

	return 0;
}