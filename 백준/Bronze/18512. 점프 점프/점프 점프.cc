#include <cstdio>
#include <unordered_set>

using namespace std;

int main(void) {
	int x, y, p1, p2;
	scanf("%d%d%d%d", &x, &y, &p1, &p2);

	while (p1 < 10000 && p2 < 10000) {
		if (p1 == p2) {
			printf("%d\n", p1);
			return 0;
		}
		else if (p1 < p2) {
			p1 += x;
		}
		else {
			p2 += y;
		}
	}

	printf("-1\n");

	return 0;
}