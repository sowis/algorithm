#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

bool distribute(const int M, const int length, const vector<int>& candies) {
	int count = 0;
	for (const int candy : candies) {
		count += candy / length;
	}

	return count >= M;
}

int main(void) {
	int M, N;
	scanf("%d%d", &M, &N);

	vector<int> candies(N);
	long long candy_sum = 0;
	int left = 1;
	int right = 0;

	for (int& candy : candies) {
		scanf("%d", &candy);
		right = max(right, candy);
		candy_sum += candy;
	}

	if (candy_sum < M) {
		printf("0");
		return 0;
	}

	int result = 0;
	while (left <= right) {
		const int mid = (left + right) / 2;

		if (distribute(M, mid, candies)) {
			result = max(result, mid);
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	printf("%d", result);

	return 0;
}