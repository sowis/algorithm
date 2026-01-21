#include <iostream>

using namespace std;

int main(void) {
	long long N;
	cin >> N;

	long long result = 1;
	for (long long i = 3; i <= N; i += 2) {
		result *= i;
	}

	cout << result;

	return 0;
}