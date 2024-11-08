#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string input;
	cin >> input;

	if (input == "fdsajkl;" || input == "jkl;fdsa") {
		cout << "in-out";
	}
	else if (input == "asdf;lkj" || input == ";lkjasdf") {
		cout << "out-in";
	}
	else if (input == "asdfjkl;") {
		cout << "stairs";
	}
	else if (input == ";lkjfdsa") {
		cout << "reverse";
	}
	else {
		cout << "molu";
	}

	return 0;
}