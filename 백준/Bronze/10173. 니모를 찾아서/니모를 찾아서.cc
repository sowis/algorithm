#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	string line;
	while (getline(cin, line)) {
		if (line == "EOI") {
			break;
		}

		for (char& c : line) {
			c = tolower(c);
		}

		if (line.find("nemo") != string::npos) {
			cout << "Found\n";
		}
		else {
			cout << "Missing\n";
		}
	}

	return 0;
}