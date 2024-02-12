#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	vector<int> edges(N);
	for (int& edge : edges) {
		scanf("%d", &edge);
	}

	sort(edges.begin(), edges.end(), greater<int>());

	for (int i = 0; i < N - 2; ++i) {
		if (edges[i] >= edges[i + 1] + edges[i + 2]) {
			continue;
		}

		printf("%d\n", edges[i] + edges[i + 1] + edges[i + 2]);
		return 0;
	}

	printf("-1\n");

	return 0;
}