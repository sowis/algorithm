#include <iostream>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b) {
	if (a < b) {
		swap(a, b);
	}

	while (b != 0) {
		long long remain = a % b;
		a = b;
		b = remain;
	}

	return a;
}

int main(void) {
	long long a, b;
	char tmp;

	cin >> a >> tmp >> b;

	const long long r = gcd(a, b);

	cout << a / r << ":" << b / r << "\n";

	return 0;
}