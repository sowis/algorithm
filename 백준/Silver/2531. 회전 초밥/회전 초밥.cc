#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main(void) {
	int N, d, k, c;
	scanf("%d%d%d%d", &N, &d, &k, &c);

	vector<int> belt(N);
	for (int& plate : belt) {
		scanf("%d", &plate);
	}

	for (int i = 0; i < k; ++i) {
		belt.push_back(belt[i]);
	}

	unordered_map<int, int> current_eat;
	for (int i = 0; i < k; ++i) {
		++current_eat[belt[i]];
	}

	int result = (int)current_eat.size();
	if (current_eat.find(c) == current_eat.end()) {
		++result;
	}

	for (int eat_begin = 1; eat_begin < N; ++eat_begin) {
		--current_eat[belt[eat_begin - 1]];
		if (current_eat[belt[eat_begin - 1]] == 0) {
			current_eat.erase(belt[eat_begin - 1]);
		}

		++current_eat[belt[eat_begin + k - 1]];

		int current_eat_count = (int)current_eat.size();
		if (current_eat.find(c) == current_eat.end()) {
			++current_eat_count;
		}

		result = max(result, current_eat_count);
	}

	printf("%d\n", result);

	return 0;
}