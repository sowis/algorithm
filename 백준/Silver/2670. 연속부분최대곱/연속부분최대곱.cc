#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	vector<double> seeds(N);
	for (double& seed : seeds) {
		scanf("%lf", &seed);
	}

	double result = numeric_limits<double>::min();

	for (int begin = 0; begin < N; ++begin) {
		double mul = 1;
		for (int end = begin + 1; end <= N; ++end) {
			mul *= seeds[end - 1];
			result = max(result, mul);
		}
	}

	printf("%.3lf\n", result);

	return 0;
}