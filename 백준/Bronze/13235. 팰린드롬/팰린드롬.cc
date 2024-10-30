#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string str;
	cin >> str;

	for (int i = 0; i < str.size(); ++i) {
		if (str[i] != str[str.size() - 1 - i]) {
			cout << "false";
			return 0;
		}
	}

	cout << "true";

	return 0;
}