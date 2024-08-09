#include <cstdio>

int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		long long S;
		scanf("%lld", &S);

		bool no = false;
		for (long long k = 2; k <= 1000000; ++k) {
			if ((S % k) == 0) {
				no = true;
				printf("NO\n");
				break;
			}
		}

		if (no == false) {
			printf("YES\n");
		}
	}

	return 0;
}