#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		vector<int> v(5);
		for (int& score : v) {
			scanf("%d", &score);
		}

		sort(v.begin(), v.end());

		if (v[3] - v[1] >= 4) {
			printf("KIN\n");
		}
		else {
			printf("%d\n", v[1] + v[2] + v[3]);
		}
	}

	return 0;
}