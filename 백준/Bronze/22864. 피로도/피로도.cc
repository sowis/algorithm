#include <cstdio>

int main(void) {
	int A, B, C, M;
	scanf("%d%d%d%d", &A, &B, &C, &M);

	int fatigue = 0;
	int work = 0;
	for (int t = 0; t < 24; ++t) {
		if (fatigue + A <= M) {
			fatigue += A;
			work += B;
		}
		else {
			fatigue -= C;
			
			if (fatigue < 0) {
				fatigue = 0;
			}
		}
	}

	printf("%d\n", work);

	return 0;
}