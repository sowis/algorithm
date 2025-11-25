#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

vector<long long> digit_numbers{ 0, 9 }; // [n] 자릿수인 숫자의 수

long long solve(const long long N, long long K) {
	long long remain = K;
	int target_digit = 1;
	for (int i = 1; i < 11; ++i) {
		remain = K;
		K -= digit_numbers[i] * i;

		if (K <= 0) {
			break;
		}
		
		++target_digit;
	}

	const long long target_N = (long long)pow(10, target_digit - 1) + (remain - 1) / target_digit;
	if (N < target_N) {
		return -1;
	}

	return to_string(target_N)[(remain - 1) % target_digit] - '0';
}

int main(void) {
	for (int i = 1; i < 11; ++i) {
		digit_numbers.push_back(digit_numbers[i] * 10);
	}

	long long N, K;
	cin >> N >> K;

	cout << solve(N, K);

	return 0;
}