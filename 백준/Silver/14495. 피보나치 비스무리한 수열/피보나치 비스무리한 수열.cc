#include <cstdio>

using namespace std;

long long arr[117];

int main(void) {
	int N;
	scanf("%d", &N);

	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;

	for (int i = 4; i < 117; ++i) {
		arr[i] = arr[i - 1] + arr[i - 3];
	}

	printf("%lld\n", arr[N]);

	return 0;
}