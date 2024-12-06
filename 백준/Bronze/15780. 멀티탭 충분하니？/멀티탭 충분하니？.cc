#include <cstdio>

int main(void) {
	int N, K;
	scanf("%d%d", &N, &K);

	int count = 0;
	for (int i = 0; i < K; ++i) {
		int multitap;
		scanf("%d", &multitap);

		count += (multitap / 2);
		if (multitap % 2) {
			++count;
		}
	}

	if (count >= N) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}

	return 0;
}