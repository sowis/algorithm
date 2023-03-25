#include <cstdio>

int main(void) {
	long long N;
	scanf("%lld", &N);

	int begin = 1, end = 1;
	long long psum = 1;
	long long result = 0;
	while (end < 10000001) {
		if (psum == N) {
			++result;
			psum -= begin;
			++begin;
		}
		else if (psum > N) {
			psum -= begin;
			++begin;
		}
		else {
			++end;
			psum += end;
		}
	}

	printf("%lld\n", result);

	return 0;
}