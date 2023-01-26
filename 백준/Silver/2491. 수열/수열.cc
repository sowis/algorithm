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

	int result = 0;

	int current = -1;
	int current_size = 0;
	for (const int number : numbers) {
		if (current <= number) {
			current = number;
			++current_size;
		}
		else {
			result = max(result, current_size);
			current_size = 1;
			current = number;
		}
	}

	result = max(result, current_size);
	current = -1;
	current_size = 0;

	reverse(numbers.begin(), numbers.end());
	for (const int number : numbers) {
		if (current <= number) {
			current = number;
			++current_size;
		}
		else {
			result = max(result, current_size);
			current_size = 1;
			current = number;
		}
	}

	result = max(result, current_size);
	printf("%d\n", result);

	return 0;
}