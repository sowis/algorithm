#include <cstdio>
#include <algorithm>

using namespace std;

int main(void) {
	int W, H, N, M;
	scanf("%d%d%d%d", &W, &H, &N, &M);

	if (W == 0 || H == 0) {
		printf("0\n");
		return 0;
	}

	const int width = ((W - 1) / (N + 1)) + 1;
	const int height = ((H - 1) / (M + 1)) + 1;
	const int result = width * height;

	printf("%d\n", result);

	return 0;
}