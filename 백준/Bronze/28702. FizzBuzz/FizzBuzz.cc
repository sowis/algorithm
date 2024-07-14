#include <string>
#include <iostream>

using namespace std;

int main(void) {
	int cur = 0;
	for (int i = 0; i < 3; ++i) {
		string input;
		cin >> input;

		if (input != "Fizz" && input != "Buzz" && input != "FizzBuzz") {
			cur = stoi(input);
		}

		++cur;
	}

	if (cur % 3 == 0 && cur % 5 == 0) {
		cout << "FizzBuzz\n";
	}
	else if (cur % 3 == 0) {
		cout << "Fizz\n";
	}
	else if (cur % 5 == 0) {
		cout << "Buzz\n";
	}
	else {
		cout << cur;
	}

	return 0;
}