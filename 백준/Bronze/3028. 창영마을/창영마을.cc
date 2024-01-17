#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int moves[3][2] = { {0, 1}, {1, 2}, {0, 2} };

int main(void) {
	string op;
	cin >> op;

	vector<int> v = { 1, 0, 0 };
	for (const char c : op) {
		swap(v[moves[c - 'A'][0]], v[moves[c - 'A'][1]]);
	}

	for (int i = 0; i < 3; ++i) {
		if (v[i] == 1) {
			cout << i + 1 << "\n";
			break;
		}
	}

	return 0;
}