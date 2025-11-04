#include <iostream>

using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		const int remain = a % b;
		a = b;
		b = remain;
	}

	return a;
}

int main(void) {
	int N, M;
	cin >> N >> M;

	cout << M - gcd(N, M);

	return 0;
}