#include <cstdio>
#include <vector>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	vector<int> v(N);
	for (int& n : v) {
		scanf("%d", &n);
	}

	vector<long long> psum(N);
	psum[0] = v[0];
	for (int i = 1; i < N; ++i) {
		psum[i] = psum[i - 1] + v[i];
	}

	long long result = 0;
	for (int i = 1; i < N; ++i) {
		result += psum[i - 1] * v[i];
	}

	printf("%lld\n", result);

	return 0;
}