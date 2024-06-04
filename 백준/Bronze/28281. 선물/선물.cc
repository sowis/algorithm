#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main(void) {
	int N, X;
	scanf("%d%d", &N, &X);

	vector<int> A(N);
	for (int& a : A) {
		scanf("%d", &a);
	}

	int result = numeric_limits<int>::max();
	for (int i = 1; i < N; ++i) {
		result = min(result, (A[i - 1] + A[i]) * X);
	}

	printf("%d\n", result);

	return 0;
}