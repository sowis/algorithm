#include <iostream>
#include <vector>

using namespace std;

vector<int> calc(const int num1, const int num2) {
	vector<int> result;
	result.push_back(num1 + num2);
	result.push_back(num1 - num2);
	result.push_back(num2 - num1);
	result.push_back(num1 * num2);

	if (num1 % num2 == 0) {
		result.push_back(num1 / num2);
	}

	if (num2 % num1 == 0) {
		result.push_back(num2 / num1);
	}

	return result;
}

bool can_make_d(const vector<int> &abc, const int d) {
	for (int i = 0; i < 3; ++i) {
		for (int k = 0; k < 3; ++k) {
			if (i == k) {
				continue;
			}

			const int j = 3 - i - k;
			const int a = abc[i];
			const int b = abc[k];
			const int c = abc[j];

			const vector<int> ab_calc = calc(a, b);
			for (const int ab : ab_calc) {
				if (ab == d) {
					return true;
				}

				const vector<int> abc_calc = calc(ab, c);
				for (const int abc : abc_calc) {
					if (abc == d) {
						return true;
					}
				}
			}
		}
	}

	return false;
}

int main(void) {
	int d;
	cin >> d;

	for (int a = 1; a <= 100; ++a) {
		if (a == d) {
			continue;
		}

		for (int b = a + 1; b <= 100; ++b) {
			if (b == d) {
				continue;
			}

			for (int c = b + 1; c <= 100; ++c) {
				if (c == d) {
					continue;
				}

				if (can_make_d({ a, b, c }, d)) {
					continue;
				}

				cout << a << " " << b << " " << c << "\n";
				return 0;
			}
		}
	}

	return 0;
}