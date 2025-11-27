#include <iostream>
#include <vector>

using namespace std;

constexpr long long impossible = -400000000;

long long cache[101][101][51];
vector<long long> numbers;

long long solve(const int begin, const int end, const int group) {
	long long& c = cache[begin][end][group];
	if (c != impossible) {
		return c;
	}

	if (group == 0) {
		return c = 0;
	}

	if (end - begin < 2 * group - 1) { // 구간 안에 group개의 그룹이 들어갈 수 없으면
		return c = impossible;
	}

	if (end <= begin) { // 구간이 존재하지 않으면
		return c = impossible;
	}

	if (group == 1) {
		long long result = impossible;
		for (int i = begin; i < end; ++i) {
			long long cur_sum = 0;
			for (int k = i; k < end; ++k) {
				cur_sum += numbers[k];
				result = max(result, cur_sum);
			}
		}

		return c = result;
	}

	long long result = impossible;
	for (int next_end = begin + 1; next_end <= end; ++next_end) {
		for (int cut = begin + 1; cut < next_end; ++cut) {
			result = max(result, solve(begin, cut, 1) + solve(cut + 1, next_end, group - 1));
		}
	}

	return c = result;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int i = 0; i < 101; ++i) {
		for (int j = 0; j < 101; ++j) {
			for (int k = 0; k < 51; ++k) {
				cache[i][j][k] = impossible;
			}
		}
	}

	int N, M;
	cin >> N >> M;

	numbers = vector<long long>(N);
	for (long long& num : numbers) {
		cin >> num;
	}

	long long result = impossible;
	for (int begin = 0; begin < N; ++begin) {
		result = max(result, solve(begin, N, M));
	}
	
	cout << result;

	return 0;
}