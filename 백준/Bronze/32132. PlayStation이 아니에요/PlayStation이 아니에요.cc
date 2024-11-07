#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int N;
	cin >> N;

	string str;
	cin >> str;

	if (str.size() <= 2) {
		cout << str;
		return 0;
	}

	string result;
	result += str[0];
	result += str[1];

	for (int i = 2; i < str.size(); ++i) {
		if (((str[i] == '4') || (str[i] == '5')) &&
			((result[result.size() - 2] == 'P') && (result[result.size() - 1] == 'S'))) {
			continue;
		}

		result += str[i];
	}

	cout << result;

	return 0;
}