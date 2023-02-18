#include <cstdio>
#include <algorithm>

using namespace std;

int main(void) {
	int N, M;
	scanf("%d%d", &N, &M);

	if (N == 1) {
		printf("1\n");
	}
	else if (N == 2) {
		printf("%d\n", min((M + 1) / 2, 4));
	}
	else if (M < 7 && N >= 3) {
		printf("%d\n", min(M, 4));
	}
	else {
		printf("%d\n", M - 7 + 5);
	}

	return 0;
}