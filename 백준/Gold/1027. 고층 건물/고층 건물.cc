#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	vector<double> heights(N);
	for (double& height : heights) {
		scanf("%lf", &height);
	}

	double gradients[51][51];
	for (int i = 0; i < N - 1; ++i) {
		for (int k = i + 1; k < N; ++k) {
			const double gradient = (heights[k] - heights[i]) / (k - i);
			gradients[i][k] = gradient;
			gradients[k][i] = gradient;
		}
	}

	int result = 0;
	for (int cur = 0; cur < N; ++cur) {
		int see_count = 0;
		for (int left = cur - 1; left >= 0; --left) {
			bool see = true;
			for (int inner = left + 1; inner < cur; ++inner) {
				if (gradients[inner][cur] <= gradients[left][cur]) {
					see = false;
					break;
				}
			}

			if (see) {
				++see_count;
			}
		}

		for (int right = cur + 1; right < N; ++right) {
			bool see = true;
			for (int inner = cur + 1; inner < right; ++inner) {
				if (gradients[inner][cur] >= gradients[cur][right]) {
					see = false;
					break;
				}
			}

			if (see) {
				++see_count;
			}
		}

		result = max(result, see_count);
	}

	printf("%d\n", result);

	return 0;
}