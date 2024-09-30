#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	int sum = 0;
	for (int i = 0; i < 4; ++i) {
		int stat;
		scanf("%d", &stat);

		sum += stat;
	}

	int N;
	scanf("%d", &N);

	printf("%d\n", max(N * 4 - sum, 0));

	return 0;
}