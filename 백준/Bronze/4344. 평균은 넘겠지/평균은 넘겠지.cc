#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

void test_case(void) {
	int N;
	scanf("%d", &N);

	vector<double> scores(N);
	double sum = 0;
	for (double& score : scores) {
		scanf("%lf", &score);
		sum += score;
	}

	const double avg = sum / N;
	double upper_avg_count = 0;

	for (const double score : scores) {
		if (score > avg) {
			++upper_avg_count;
		}
	}

	printf("%.3lf%%\n", round((upper_avg_count / N) * 100000) / 1000);
}

int main(void) {
	int C;
	scanf("%d", &C);

	for (int i = 0; i < C; ++i) {
		test_case();
	}

	return 0;
}