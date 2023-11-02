#include <cstdio>
#include <algorithm>

using namespace std;

int main(void) {
	int N, P;
	scanf("%d%d", &N, &P);

	int result = P;

	if (N >= 5) {
		result = min(result, P - 500);
	}

	if (N >= 10) {
		result = min(result, (int)(P * 0.9));
	}

	if (N >= 15) {
		result = min(result, P - 2000);
	}

	if (N >= 20) {
		result = min(result, (int)(P * 0.75));
	}

	if (result < 0) {
		result = 0;
	}

	printf("%d\n", result);

	return 0;
}