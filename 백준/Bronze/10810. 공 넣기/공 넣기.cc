#include <cstdio>
#include <vector>

using namespace std;

int main(void) {
	int N, M;
	scanf("%d%d", &N, &M);

	vector<int> basket(N, 0);
	for (int a = 0; a < M; ++a) {
		int i, j, k;
		scanf("%d%d%d", &i, &j, &k);

		for (int b = i - 1; b < j; ++b) {
			basket[b] = k;
		}
	}

	for (const int result : basket) {
		printf("%d ", result);
	}

	return 0;
}