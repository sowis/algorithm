#include <cstdio>
#include <vector>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	vector<int> prices(N);
	for (int& p : prices) {
		scanf("%d", &p);
	}

	int M;
	scanf("%d", &M);

	int result = 0;
	for (int i = 0; i < M; ++i) {
		int id;
		scanf("%d", &id);

		result += prices[id - 1];
	}

	printf("%d\n", result);

	return 0;
}