#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N, M;
	scanf("%d%d", &N, &M);

	vector<int> numbers(M);
	for (int& num : numbers) {
		scanf("%d", &num);
	}

	sort(numbers.begin(), numbers.end());

	int my_price = 0;
	int max_price = 0;
	for (int i = 0; i < M; ++i) {
		const int buy_count = min(M - i, N);
		const int price = buy_count * numbers[i];
		
		if (max_price < price) {
			max_price = price;
			my_price = numbers[i];
		}
	}

	printf("%d %d\n", my_price, max_price);

	return 0;
}