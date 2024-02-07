#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

inline double dist(const pair<int, int>& p1, const pair<int, int>& p2) {
	return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

int main(void) {
	int N;
	scanf("%d", &N);

	vector<pair<int, int>> v(N);
	for (pair<int, int>& p : v) {
		scanf("%d%d", &p.first, &p.second);
	}

	double dist_sum = 0;
	for (int i = 0; i < N - 1; ++i) {
		for (int k = i + 1; k < N; ++k) {
			dist_sum += dist(v[i], v[k]);
		}
	}

	const double result = dist_sum * 2 / N;
	printf("%.7lf\n", result);

	return 0;
}