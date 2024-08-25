#include <cstdio>
#include <deque>
#include <algorithm>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	deque<double> v(7, 99999);
	for (int i = 0; i < N; ++i) {
		double d;
		scanf("%lf", &d);

		if (v[6] <= d) {
			continue;
		}

		v.push_back(d);
		sort(v.begin(), v.end());
		v.pop_back();
	}

	for (const double d : v) {
		printf("%.3lf\n", d);
	}

	return 0;
}