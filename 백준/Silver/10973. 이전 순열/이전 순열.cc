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

	if (prev_permutation(numbers.begin(), numbers.end()) == false) {
		printf("-1\n");
		return 0;
	}
	
	for (const int number : numbers) {
		printf("%d ", number);
	}

	return 0;
}