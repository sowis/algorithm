#include <cstdio>
#include <vector>

using namespace std;

constexpr int numbers[4] = { 1, 5, 10, 50 };

vector<vector<bool>> visit(21, vector<bool>(50 * 20 + 1, false));

int solve(const int remain, const int sum) {
	if (visit[remain][sum]) {
		return 0;
	}

	visit[remain][sum] = true;

	if (remain == 0) {
		return 1;
	}

	int result = 0;
	for (int i = 0; i < 4; ++i) {
		const int next_sum = sum + numbers[i];
		result += solve(remain - 1, next_sum);
	}

	return result;
}

int main(void) {
	int N;
	scanf("%d", &N);

	const int result = solve(N, 0);
	printf("%d\n", result);

	return 0;
}