#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N, L, K;
	scanf("%d%d%d", &N, &L, &K);

	vector<int> qs;
	for (int i = 0; i < N; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);

		if (a > L && b > L) {
			continue;
		}
		else if (a <= L && b > L) {
			qs.push_back(100);
		}
		else {
			qs.push_back(140);
		}
	}

	sort(qs.begin(), qs.end(), greater<int>());

	int result = 0;
	for (int i = 0; i < min(K, (int)qs.size()); ++i) {
		result += qs[i];
	}

	printf("%d\n", result);

	return 0;
}