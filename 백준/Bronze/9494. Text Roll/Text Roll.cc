#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	while (true) {
		string input;
		getline(cin, input);
		int line_count = stoi(input);

		if (line_count == 0) {
			break;
		}

		vector<string> lines(line_count);
		for (string& line : lines) {
			getline(cin, line);
		}

		int x = 0;
		for (int y = 0; y < line_count; ++y) {
			int drop_point = max(x, (int)lines[y].size());
			for (int cur = x; cur < lines[y].size(); ++cur) {
				if (lines[y][cur] == ' ') {
					drop_point = cur;
					break;
				}
			}

			x = max(drop_point, x);
		}

		cout << x + 1 << "\n";
	}

	return 0;
}