#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b) {
	while (b != 0) {
		const long long remain = a % b;
		a = b;
		b = remain;
	}

	return a;
}

long long first_to_last(long long num) {
	long long n = num;
	long long first_num = 0;
	int digit = 0;
	while (n != 0) {
		first_num = n % 10;
		n /= 10;
		++digit;
	}

	num %= (long long)pow(10, digit - 1);
	num *= 10;
	num += first_num;
	return num;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	double X;
	cin >> X;

	if (X == 10) {
		cout << "No solution\n";
		return 0;
	}

	const long long div = gcd((long long)(X * 10000), 10000);
	const long long mother = 10000 / div;
	const long long child = (long long)(X * 10000) / div;

	vector<long long> results;
	for (long long first_num = 1; first_num <= 9; ++first_num) {
		for (long long digit = 1; digit <= 8; ++digit) {
			const double d_remain_num = (first_num * (mother - child * pow(10, digit - 1))) / (child - 10 * mother);
			if (d_remain_num != floor(d_remain_num)) { // 정수인지 확인
				continue;
			}

			const long long remain_num = (long long)floor(d_remain_num);

			int remain_digit = 0;
			while (remain_num / (int)pow(10, remain_digit) != 0) {
				++remain_digit;
			}

			if (remain_digit + 1 > 9) { // 자연수의 크기가 10^8이 넘지 않는지 확인
				continue;
			}

			const long long result = first_num * (long long)pow(10, remain_digit) + remain_num;

			if (child * result == mother * first_to_last(result)) {
				results.push_back(result);
			}
		}
	}

	sort(results.begin(), results.end());
	if (results.empty()) {
		cout << "No solution";
		return 0;
	}

	for (const long long result : results) {
		cout << result << "\n";
	}

	return 0;
}