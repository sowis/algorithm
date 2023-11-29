#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		vector<int> v(3);
		for (int& num : v) {
			scanf("%d", &num);
		}

		sort(v.begin(), v.end());

		printf("Scenario #%d:\n", i + 1);

		if (v[0] * v[0] + v[1] * v[1] == v[2] * v[2]) {
			printf("yes\n");
		}
		else {
			printf("no\n");
		}

		printf("\n");
	}


	return 0;
}