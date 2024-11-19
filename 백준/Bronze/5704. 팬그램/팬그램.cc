#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	while (true) {
		string str;
		getline(cin, str);

		if (str == "*") {
			break;
		}

		vector<bool> check(127, false);
		for (const char c : str) {
			check[c] = true;
		}

		bool all_exist = true;
		for (int i = 'a'; i <= 'z'; ++i) {
			if (check[i] == false) {
				all_exist = false;
				break;
			}
		}

		cout << (all_exist ? "Y" : "N") << "\n";
	}

	return 0;
}