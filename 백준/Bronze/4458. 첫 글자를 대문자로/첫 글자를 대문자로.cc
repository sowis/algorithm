#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string line;
	getline(cin, line);

	while (getline(cin, line)) {
		if ('a' <= line[0] && line[0] <= 'z') {
			line[0] = line[0] - 'a' + 'A';
		}

		cout << line << "\n";
	}

	return 0;
}