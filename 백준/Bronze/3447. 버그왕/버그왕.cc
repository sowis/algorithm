#include <iostream>
#include <vector>
#include <string>

using namespace std;

const char* BUG = "BUG";

int main(void) {
	string line;

	while (getline(cin, line)) {
		bool find_bug = false;
		string cur_line = line;
		string new_line;

		do {
			find_bug = false;
			int bug_index = 0;
			vector<char> v;

			for (const char buffer : cur_line) {
				if (buffer == BUG[bug_index]) {
					++bug_index;
					v.push_back(buffer);

					if (bug_index == 3) {
						bug_index = 0;
						v.clear();
						find_bug = true;
					}
				}
				else if (buffer == BUG[0]) {
					for (const char c : v) {
						new_line += c;
					}

					bug_index = 1;
					v.clear();
					v.push_back(BUG[0]);
				}
				else {
					for (const char c : v) {
						new_line += c;
					}

					new_line += buffer;
					bug_index = 0;
					v.clear();
				}
			}

			for (const char c : v) {
				new_line += c;
			}

			cur_line = new_line;
			new_line = "";
		} while (find_bug);

		cout << cur_line << "\n";
	}

	return 0;
}