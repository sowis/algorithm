#include <cstdio>
#include <vector>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	vector<int> pos(5);
	for (int i = 1; i <= N; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);

		if (y == 0 || x == 0) {
			++pos[0];
		}
		else if (y > 0 && x > 0) {
			++pos[1];
		}
		else if (y > 0 && x < 0) {
			++pos[2];
		}
		else if (y < 0 && x < 0) {
			++pos[3];
		}
		else {
			++pos[4];
		}
	}

	for (int i = 1; i <= 4; ++i) {
		printf("Q%d: %d\n", i, pos[i]);
	}

	printf("AXIS: %d\n", pos[0]);

	return 0;
}