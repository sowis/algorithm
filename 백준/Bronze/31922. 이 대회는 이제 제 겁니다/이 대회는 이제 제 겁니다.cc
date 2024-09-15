#include <cstdio>
#include <algorithm>

using namespace std;

int main(void) {
	int a, p, c;
	scanf("%d%d%d", &a, &p, &c);

	printf("%d\n", max(a + c, p));

	return 0;
}