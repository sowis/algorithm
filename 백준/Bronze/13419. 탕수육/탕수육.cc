#include <iostream>
#include <string>

using namespace std;

void test_case(void) {
	string input;
	cin >> input;

	if (input.size() % 2) {
		input += input;
	}

	string first_repeat;
	for (int i = 0; i < input.size(); i += 2) {
		first_repeat += input[i];
	}

	string second_repeat;
	for (int i = 1; i < input.size(); i += 2) {
		second_repeat += input[i];
	}

	cout << first_repeat << "\n";
	cout << second_repeat << "\n";
}

int main(void) {
	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		test_case();
	}

	return 0;
}