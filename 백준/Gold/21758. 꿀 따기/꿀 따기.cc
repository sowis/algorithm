#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	vector<int> honeies(N);
	for (int& honey : honeies) {
		scanf("%d", &honey);
	}

	vector<int> psum(N);
	psum[0] = honeies[0];
	for (int i = 1; i < N; ++i) {
		psum[i] = psum[i - 1] + honeies[i];
	}

	int mid_max = 0;
	for (int i = 1; i < N - 1; ++i) {
		mid_max = max(mid_max, honeies[i]);
	}

	int result = psum[N - 2] - psum[0] + mid_max;
	for (int left_inside = 1; left_inside < N - 1; ++left_inside) {
		result = max(result, psum[N - 1] - psum[0] - honeies[left_inside] + psum[N - 1] - psum[left_inside]);
	}

	for (int right_inside = 1; right_inside < N - 1; ++right_inside) {
		result = max(result, psum[N - 2] - honeies[right_inside] + psum[right_inside - 1]);
	}

	printf("%d\n", result);

	return 0;
}