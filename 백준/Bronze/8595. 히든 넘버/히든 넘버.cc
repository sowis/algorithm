#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int N;
	cin >> N;

	string input;
	cin >> input;

	long long result = 0;
	bool last_is_number = false;
	int number_buffer = 0;
	for (int i = 0; i < N; ++i) {
		if (input[i] < '0' || input[i] > '9') {
			result += number_buffer;
			number_buffer = 0;
			last_is_number = false;
		}
		else {
			number_buffer = number_buffer * 10 + (input[i] - '0');
			last_is_number = true;
		}
	}

	if (last_is_number) {
		result += number_buffer;
	}

	cout << result << "\n";

	return 0;
}