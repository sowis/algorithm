#include <iostream>

using namespace std;

int main(void) {
	char name;
	cin >> name;

	if (name == 'M') {
		cout << "MatKor";
	}
	else if (name == 'W') {
		cout << "WiCys";
	}
	else if (name == 'C') {
		cout << "CyKor";
	}
	else if (name == 'A') {
		cout << "AlKor";
	}
	else {
		cout << "$clear";
	}

	return 0;
}