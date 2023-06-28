#include <cstdio>
#include <algorithm>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);

	const int result = min(a, N) + min(b, N) + min(c, N);
	printf("%d\n", result);

	return 0;
}