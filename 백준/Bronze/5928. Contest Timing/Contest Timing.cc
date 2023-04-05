#include <cstdio>

using namespace std;

int main(void) {
	int D, H, M;
	scanf("%d%d%d", &D, &H, &M);

	const int time = M + (H * 60) + (D * 24 * 60);
	const int begin = 11 + (11 * 60) + (11 * 24 * 60);

	if (time < begin) {
		printf("-1\n");
	}
	else {
		printf("%d\n", time - begin);
	}

	return 0;
}