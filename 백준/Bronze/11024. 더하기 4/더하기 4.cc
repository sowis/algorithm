#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(void) {
	string T;
	getline(cin, T);

	for (int i = 0; i < stoi(T); ++i) {
		string line;
		getline(cin, line);

		stringstream ss(line);
		int result = 0;
		int tmp;

		while (ss >> tmp) {
			result += tmp;
		}

		cout << result << "\n";
	}

	return 0;
}