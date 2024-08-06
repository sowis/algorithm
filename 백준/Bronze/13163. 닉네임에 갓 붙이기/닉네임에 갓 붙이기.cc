#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(void) {
	string N;
	getline(cin, N);

	for (int i = 0; i < stoi(N); ++i) {
		string line;
		getline(cin, line);

		stringstream ss(line);
		bool first = true;
		string result = "god";
		string tmp;
		while (ss >> tmp) {
			if (first) {
				first = false;
				continue;
			}

			result += tmp;
		}

		cout << result << "\n";
	}

	return 0;
}