#include <iostream>
#include <string>
#include <vector>

using namespace std;

int find_R(const int size) {
	int result = 1;
	for (int i = 1; i <= size; ++i) {
		if (size % i) {
			continue;
		}

		if (i > size / i) {
			break;
		}

		result = i;
	}

	return result;
}

int main(void) {
	string str;
	cin >> str;

	const int R = find_R((int)str.size());
	const int C = (int)str.size() / R;
	vector<vector<char>> v(R, vector<char>(C));

	int i = 0;
	for (int x = 0; x < C; ++x) {
		for (int y = 0; y < R; ++y) {
			v[y][x] = str[i];
			++i;
		}
	}

	for (int y = 0; y < R; ++y) {
		for (int x = 0; x < C; ++x) {
			cout << v[y][x];
		}
	}

	return 0;
}