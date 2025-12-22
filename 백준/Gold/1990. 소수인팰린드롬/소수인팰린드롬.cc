#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int seed_to_palindrome(int seed) {
	int result = seed;
	seed /= 10;

	while (seed > 0) {
		result *= 10;
		result += seed % 10;
		seed /= 10;
	}
	
	return result;
}

bool is_prime(const int num) {
	const int sqt = (int)sqrt(num);
	for (int base = 2; base <= sqt; ++base) {
		if (num % base == 0) {
			return false;
		}
	}

	return true;
}

int main(void) {
	int a, b;
	cin >> a >> b;

	for (int seed = 1; seed < 100000; ++seed) {
		if (seed == 9 && a <= 11 && 11 <= b) {
			cout << "11\n";
		}

		const int target = seed_to_palindrome(seed);
		if (target < a) {
			continue;
		}

		if (b < target) {
			break;
		}

		if (is_prime(target)) {
			cout << target << "\n";
		}
	}

	cout << -1;

	return 0;
}