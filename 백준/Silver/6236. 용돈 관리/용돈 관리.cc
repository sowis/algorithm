#include <cstdio>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int N, M;
vector<int> prices;
int max_price;

bool available(const int K) {
	int money = 0;
	int draw_count = 0;

	if (K < max_price) {
		return false;
	}

	for (const int price : prices) {
		if (money < price) {
			money = K;
			++draw_count;
		}

		money -= price;
	}

	if (draw_count <= M) {
		return true;
	}
	else {
		return false;
	}
}

int main(void) {
	scanf("%d%d", &N, &M);

	prices = vector<int>(N);
	for (int& p : prices) {
		scanf("%d", &p);

		max_price = max(max_price, p);
	}

	int left = 1;
	int right = 100000 * 10000;
	int min_ok = numeric_limits<int>::max();

	while (left <= right) {
		const int mid = (left + right) / 2;

		if (available(mid)) {
			min_ok = min(min_ok, mid);
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	printf("%d\n", min_ok);

	return 0;
}