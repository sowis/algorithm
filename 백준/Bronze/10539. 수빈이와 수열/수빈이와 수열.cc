#include <cstdio>
#include <vector>

using namespace std;

long long A[101];
long long B[101];
long long psum[101];

int main(void) {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%lld", &B[i]);
	}

	A[0] = B[0];
	psum[0] = A[0];

	for (int i = 1; i < n; ++i) {
		A[i] = B[i] * (i + 1) - psum[i - 1];
		psum[i] = psum[i - 1] + A[i];
	}

	for (int i = 0; i < n; ++i) {
		printf("%lld ", A[i]);
	}

	return 0;
}