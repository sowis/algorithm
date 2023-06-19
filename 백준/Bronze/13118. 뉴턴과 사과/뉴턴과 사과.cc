#include <cstdio>
#include <vector>

using namespace std;

int main(void) {
	vector<int> p(4);
	for (int i = 0; i < 4; ++i) {
		scanf("%d", &p[i]);
	}

	int x, y, r;
	scanf("%d%d%d", &x, &y, &r);

	for (int i = 0; i < 4; ++i) {
		if (x == p[i]) {
			printf("%d\n", i + 1);
			return 0;
		}
	}

	printf("0\n");

	return 0;
}