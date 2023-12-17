#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main(void) {
	int n;
	int scn = 1;

	while (true) {
		string input;
		getline(cin, input);
		n = stoi(input);
		if (n == 0) {
			break;
		}

		vector<string> names(n);
		for (string& name : names) {
			getline(cin, name);
		}

		vector<bool> rtn(n, true);
		for (int i = 0; i < 2 * n - 1; ++i) {
			getline(cin, input);
			stringstream ss(input);
			int num, c;
			ss >> num >> c;

			rtn[num - 1] = !rtn[num - 1];
		}

		for (int i = 0; i < n; ++i) {
			if (rtn[i] == false) {
				cout << scn << " " << names[i] << "\n";
			}
		}

		++scn;
	}

	return 0;
}