#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int max_value = -1987654321;
int min_value = 1987654321;

void calc(const vector<int>& numbers, vector<int>& op_counts, const int idx, const int value) {
	if (idx == numbers.size()) {
		max_value = max(max_value, value);
		min_value = min(min_value, value);
		return;
	}
	
	for (int i = 0; i < 4; ++i) {
		if (op_counts[i] == 0) {
			continue;
		}

		--op_counts[i];

		if (i == 0) {
			calc(numbers, op_counts, idx + 1, value + numbers[idx]);
		}
		else if (i == 1) {
			calc(numbers, op_counts, idx + 1, value - numbers[idx]);
		}
		else if (i == 2) {
			calc(numbers, op_counts, idx + 1, value * numbers[idx]);
		}
		else {
			calc(numbers, op_counts, idx + 1, value / numbers[idx]);
		}

		++op_counts[i];
	}
}

int main(void) {
	int N;
	scanf("%d", &N);

	vector<int> numbers(N);
	for (int& num : numbers) {
		scanf("%d", &num);
	}

	vector<int> op_counts(4);
	for (int& count : op_counts) {
		scanf("%d", &count);
	}

	calc(numbers, op_counts, 1, numbers[0]);

	printf("%d\n", max_value);
	printf("%d\n", min_value);

	return 0;
}