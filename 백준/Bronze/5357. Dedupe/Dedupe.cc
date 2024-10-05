#include <string>
#include <iostream>

using namespace std;

void test_case(void) {
	string input;
	cin >> input;

	string result;
	char last = -1;
	for (const char c : input) {
		if (c == last) {
			continue;
		}

		result += c;
		last = c;
	}

	cout << result << "\n";
}

int main(void) {
	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		test_case();
	}

	return 0;
}