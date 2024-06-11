#include <cstdio>
#include <algorithm>

using namespace std;

int main(void) {
	int N, M;
	scanf("%d%d", &N, &M);

	bool find = false;
	int y1, x1;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			int num;
			scanf("%d", &num);

			if (num == 1) {
				if (find == false) {
					y1 = y;
					x1 = x;
					find = true;
				}
				else {
					printf("%d", abs(y1 - y) + abs(x1 - x));
					return 0;
				}
			}
		}
	}

	return 0;
}