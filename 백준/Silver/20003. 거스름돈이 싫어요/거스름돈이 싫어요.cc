#include <iostream>
#include <vector>

using namespace std;

long long gcd(long long a, long long b) {
	while (b != 0) {
		const long long div = a % b;
		a = b;
		b = div;
	}

	return a;
}

long long lcm(long long a, long long b) {
	return (a / gcd(a, b)) * b;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;


	long long result_child = 0;
	long long result_mother = 1;
	for (int i = 0; i < N; ++i) {
		long long child, mother;
		cin >> child >> mother;

		const long long div = gcd(child, mother);
		child /= div;
		mother /= div;

		result_child = gcd(result_child, child);
		result_mother = lcm(result_mother, mother);
	}

	cout << result_child << " " << result_mother;

	return 0;
}