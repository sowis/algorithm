#include <iostream>
#include <string>

using namespace std;

int clap(const int num) {
	const string str = to_string(num);
	int result = 0;
	for (const char c : str) {
		if (c == '3' || c == '6' || c == '9') {
			++result;
		}
	}

	return result;
}

int main(void) {
	int N;
	cin >> N;

	long long result = 0;
	for (int num = 1; num <= N; ++num) {
		result += clap(num);
	}

	cout << result;

	return 0;
}