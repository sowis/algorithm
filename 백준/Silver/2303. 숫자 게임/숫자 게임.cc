#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int get_max_value(const vector<int>& scores) {
	int result = 0;
	for (int a = 0; a < 3; ++a) {
		for (int b = a + 1; b < 4; ++b) {
			for (int c = b + 1; c < 5; ++c) {
				result = max(result, (scores[a] + scores[b] + scores[c]) % 10);
			}
		}
	}

	return result;
}

int main(void) {
	int N;
	scanf("%d", &N);

	vector<vector<int>> scores(N, vector<int>(5));
	vector<int> max_values;
	for (vector<int>& score : scores) {
		for (int& s : score) {
			scanf("%d", &s);
		}

		max_values.push_back(get_max_value(score));
	}

	int max_score = 0;
	int winner;
	for (int i = 0; i < N; ++i) {
		if (max_values[i] >= max_score) {
			max_score = max_values[i];
			winner = i + 1;
		}
	}

	printf("%d\n", winner);

	return 0;
}