#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string input;
	while (true) {
		getline(cin, input);
		if (input == "#") {
			break;
		}
		
		char target = input[0];
		int result = -1;
		
		for (const char c : input) {
			if ((c == target) || ((c - 'A' + 'a') == target)) {
				++result;
			}
		}

		cout << target << " " << result << "\n";
	}

	return 0;
}