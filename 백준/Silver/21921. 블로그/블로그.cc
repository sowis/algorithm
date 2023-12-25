#include <cstdio>
#include <vector>

using namespace std;

int main(void) {
	int N, X;
	scanf("%d%d", &N, &X);

	vector<int> v(N);
	for (int& num : v) {
		scanf("%d", &num);
	}

	int cur_sum = 0;
	for (int i = 0; i < X; ++i) {
		cur_sum += v[i];
	}

	int max_sum = cur_sum;
	int max_count = 1;

	for (int i = X; i < N; ++i) {
		cur_sum -= v[i - X];
		cur_sum += v[i];

		if (cur_sum > max_sum) {
			max_sum = cur_sum;
			max_count = 1;
		}
		else if (cur_sum == max_sum) {
			++max_count;
		}
	}

	if (max_sum == 0) {
		printf("SAD\n");
		return 0;
	}
	printf("%d\n", max_sum);
	printf("%d\n", max_count);

	return 0;
}