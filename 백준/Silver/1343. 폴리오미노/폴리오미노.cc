#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string str;
	cin >> str;

	for (int i = 0; i < str.size();) {
		if (str[i] == '.') {
			++i;
			continue;
		}
		
		if (i + 4 <= str.size() && str[i + 1] == 'X' && str[i + 2] == 'X' && str[i + 3] == 'X') {
			str[i] = str[i + 1] = str[i + 2] = str[i + 3] = 'A';
			i += 4;
			continue;
		}

		if (i + 2 <= str.size() && str[i + 1] == 'X') {
			str[i] = str[i + 1] = 'B';
			i += 2;
			continue;
		}
		
		cout << -1;
		return 0;
	}

	cout << str;

	return 0;
}