#include <cstdio>
#include <algorithm>

using namespace std;

int main(void) {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);

	int result = min(2 * b + 4 * c, 2 * a + 2 * c);
	result = min(result, 4 * a + 2 * b);

	printf("%d\n", result);

	return 0;
}