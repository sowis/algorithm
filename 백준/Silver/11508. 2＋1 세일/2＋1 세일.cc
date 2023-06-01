#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	vector<int> prices(N);
	for (int &price : prices) {
		scanf("%d", &price);
	}

	sort(prices.begin(), prices.end(), greater<int>());

	int result = 0;
	for (int i = 2; i < N; i += 3) {
		result += prices[i - 2];
		result += prices[i - 1];
	}

	for (int i = 0; i < N % 3; ++i) {
		result += prices[N - 1 - i];
	}

	printf("%d\n", result);

	return 0;
}