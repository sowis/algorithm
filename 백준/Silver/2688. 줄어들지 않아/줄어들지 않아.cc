#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> cache(65, vector<long long>(10, -1)); // [자릿수][시작숫자] = 줄어들지 않는 수의 개수

long long solve(const int digit, const int begin) {
	long long& c = cache[digit][begin];
	if (c != -1) {
		return c;
	}

	if (digit <= 1) {
		return c = 1;
	}

	long long result = 0;
	for (int next_begin = begin; next_begin <= 9; ++next_begin) {
		result += solve(digit - 1, next_begin);
	}

	return c = result;
}

void test_case(void) {
	int N;
	cin >> N;

	long long result = 0;
	for (int begin = 0; begin <= 9; ++begin) {
		result += cache[N][begin];
	}

	cout << result << "\n";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int begin = 0; begin <= 9; ++begin) {
		solve(64, begin);
	}

	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		test_case();
	}

	return 0;
}