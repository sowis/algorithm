#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N, M;
	scanf("%d%d", &N, &M);

	vector<int> numbers(N);
	for (int& n : numbers) {
		scanf("%d", &n);
	}

	sort(numbers.begin(), numbers.end());

	vector<bool> visit(N, false);
	int result = 0;

	for (int i = 0; i < N - 1; ++i) {
		if (visit[i]) {
			continue;
		}

		for (int k = i + 1; k < N; ++k) {
			if (visit[k]) {
				continue;
			}

			if (numbers[i] + numbers[k] == M) {
				++result;
				visit[i] = true;
				visit[k] = true;
				break;
			}
		}
	}

	printf("%d\n", result);

	return 0;
}