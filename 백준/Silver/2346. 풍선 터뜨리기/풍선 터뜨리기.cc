#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	vector<int> numbers;
	for (int i = 0; i < N; ++i) {
		int input;
		scanf("%d", &input);

		numbers.push_back(input);
	}

	vector<int> valid(N, true);
	int current = 0;
	for (int i = 0; i < N - 1; ++i) {
		printf("%d ", current + 1);
		valid[current] = false;

		const int direction = (numbers[current] < 0) ? -1 : 1;
		const int to_move = abs(numbers[current]);

		for (int move_count = 0; move_count < to_move;) {
			current += direction;
			if (current == -1) {
				current = N - 1;
			}

			if (current == N) {
				current = 0;
			}

			if (valid[current]) {
				++move_count;
			}
		}
	}

	printf("%d\n", current + 1);
	
	return 0;
}