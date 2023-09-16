#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	vector<int> numbers(N);
	vector<int> scores(1000001, 0);
	vector<bool> exists(1000001, false);

	for (int i = 0; i < N; ++i) {
		int num;
		scanf("%d", &num);

		numbers[i] = num;
		exists[num] = true;
	}

	for (const int num : numbers) {
		for (int mul = 2; mul * num < 1000001; ++mul) {
			if (exists[mul * num] == false) {
				continue;
			}

			++scores[num];
			--scores[mul * num];
		}
	}

	for (const int num : numbers) {
		printf("%d ", scores[num]);
	}

	return 0;
}