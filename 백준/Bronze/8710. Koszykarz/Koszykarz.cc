#include <cstdio>

using namespace std;

int main(void) {
	int k, w, m;
	scanf("%d%d%d", &k, &w, &m);

	int mul = 0;
	while (k + m * mul < w) {
		++mul;
	}

	printf("%d\n", mul);

	return 0;
}