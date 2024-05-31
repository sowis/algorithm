#include <cstdio>
#include <algorithm>

using namespace std;

int main(void) {
	int a, b;
	scanf("%d%d", &a, &b);

	const int result = min(a - 1, b) * 2 + 1;

	printf("%d\n", result);

	return 0;
}