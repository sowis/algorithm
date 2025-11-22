#include <iostream>

using namespace std;

int main(void) {
	int N;
	cin >> N;

	long long result = 0;
	for (int i = 0; i < N; ++i) {
		long long num;
		cin >> num;

		result += num;
	}

	cout << result;

	return 0;
}