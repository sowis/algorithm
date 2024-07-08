#include <cstdio>
#include <algorithm>

using namespace std;

int main(void) {
	int n, h, v;
	scanf("%d%d%d", &n, &h, &v);

	const int result = max(h, n - h) * max(v, n - v) * 4;
	printf("%d\n", result);

	return 0;
}