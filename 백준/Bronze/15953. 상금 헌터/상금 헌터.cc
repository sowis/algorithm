#include <cstdio>
#include <vector>

using namespace std;

vector<int> price_count[2] = { {1, 2, 3, 4, 5, 6}, {1, 2, 4, 8, 16} };
vector<int> price[2] = { {5000000, 3000000, 2000000, 500000, 300000, 100000}, {5120000, 2560000, 1280000, 640000, 320000} };

int price_cal(const int rank, const int time) {
	if (rank == 0) {
		return 0;
	}
	
	int count = 0;
	for (int i = 0; i < price_count[time].size(); ++i) {
		if (rank <= count + price_count[time][i]) {
			return price[time][i];
		}

		count += price_count[time][i];
	}

	return 0;
}

int main(void) {
	int T;
	scanf("%d", &T);

	int a, b;
	for (int i = 0; i < T; ++i) {
		scanf("%d%d", &a, &b);

		const int result = price_cal(a, 0) + price_cal(b, 1);
		printf("%d\n", result);
	}

	return 0;
}