#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
	if (a < b) {
		swap(a, b);
	}

	while (b > 0) {
		const int remain = a % b;
		a = b;
		b = remain;
	}

	return a;
}

inline int lcm(const int a, const int b) {
	return a / gcd(a, b) * b;
}

int main(void) {
	vector<int> numbers(5);
	for (int& number : numbers) {
		scanf("%d", &number);
	}

	int result = 98764321;
	for (int a = 0; a < 5; ++a) {
		for (int b = a + 1; b < 5; ++b) {
			for (int c = b + 1; c < 5; ++c) {
				result = min(result, lcm(lcm(numbers[a], numbers[b]), numbers[c]));
			}
		}
	}

	printf("%d\n", result);

	return 0;
}