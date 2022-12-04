#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<string> lines(5);
	int max_len = 0;

	for (string& line : lines) {
		cin >> line;
		max_len = max(max_len, (int)line.size());
	}

	vector<char> result;
	for (int x = 0; x < max_len; ++x) {
		for (int y = 0; y < 5; ++y) {
			const string& line = lines[y];
			if (x >= line.size()) {
				continue;
			}

			result.push_back(line[x]);
		}
	}

	for (const char c : result) {
		cout << c;
	}

	return 0;
}