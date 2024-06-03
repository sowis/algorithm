#include <cstdio>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

void test_case(void) {
	int n, m;
	scanf("%d%d", &n, &m);

	vector<int> wins(n + 1, 0);
	vector<int> loses(n + 1, 0);

	for (int i = 0; i < m; ++i) {
		int a, b, p, q;
		scanf("%d%d%d%d", &a, &b, &p, &q);

		wins[a] += p;
		wins[b] += q;
		loses[b] += p;
		loses[a] += q;
	}

	double min_e = numeric_limits<double>::max();
	double max_e = numeric_limits<double>::min();
	for (int i = 1; i <= n; ++i) {
		if (wins[i] == 0 && loses[i] == 0) {
			min_e = min(min_e, 0.0);
			max_e = max(max_e, 0.0);
			continue;
		}

		const double e = (double)(wins[i] * wins[i]) / (double)(wins[i] * wins[i] + loses[i] * loses[i]);
		min_e = min(min_e, e);
		max_e = max(max_e, e);
	}

	printf("%d\n", (int)(max_e * 1000));
	printf("%d\n", (int)(min_e * 1000));
}

int main(void) {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		test_case();
	}

	return 0;
}