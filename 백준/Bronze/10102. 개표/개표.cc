#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int V;
	cin >> V;

	string input;
	cin >> input;

	int a = 0, b = 0;
	for (const char vote : input) {
		if (vote == 'A') {
			++a;
		}
		else {
			++b;
		}
	}

	if (a > b) {
		cout << "A\n";
	}
	else if (a < b) {
		cout << "B\n";
	}
	else {
		cout << "Tie\n";
	}
	
	return 0;
}