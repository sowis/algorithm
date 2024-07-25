#include <string>
#include <iostream>

using namespace std;

int main(void) {
	string input;

	while (getline(cin, input)) {
		for (char& c : input) {
			if (c == 'i') {
				c = 'e';
			}
			else if (c == 'e')
			{
				c = 'i';
			}
			else if (c == 'I') {
				c = 'E';
			}
			else if (c == 'E') {
				c = 'I';
			}
		}

		cout << input << "\n";
	}

	return 0;
}