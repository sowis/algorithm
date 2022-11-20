#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	vector<int> numbers(N);
	for (int& number : numbers) {
		scanf("%d", &number);
	}

	sort(numbers.begin(), numbers.end(), greater<int>());

	for (const int number : numbers) {
		printf("%d\n", number);
	}

	return 0;
}