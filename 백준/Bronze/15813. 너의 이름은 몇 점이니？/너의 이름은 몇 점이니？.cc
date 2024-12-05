#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int N;
	cin >> N;

	string name;
	cin >> name;

	int result = 0;
	for (const char c : name) {
		result += c - 'A' + 1;
	}

	cout << result << "\n";

	return 0;
}