#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string target;
	cin >> target;

	int N;
	cin >> N;

	int result = 0;
	for (int i = 0; i < N + 2; ++i) {
		string line;
		cin >> line;

		line += line;
		if (line.find(target) != string::npos) {
			++result;
		}
	}

	cout << result << "\n";

	return 0;
}