#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_set>

using namespace std;

constexpr int EMPTY = -1;
constexpr int RED = 0;
constexpr int BLUE = 1;


void test_case(void) {
	string line;
	getline(cin, line);
	if (line == "") {
		getline(cin, line);
	}

	stringstream ss(line);

	int n, m;
	ss >> n >> m;
	
	vector<vector<int>> nears(m);
	for (int i = 0; i < m; ++i) {
		getline(cin, line);
		int num;
		ss = stringstream(line);

		while (ss >> num) {
			nears[i].push_back(num);
		}
	}
	
	unordered_set<int> sets;
	for (int i = 0; i < m; ++i) {
		if (nears.size() == 1) {
			cout << "N";
			return;
		}

		int s = 0;
		for (const int near : nears[i]) {
			s |= (1 << (near - 1)); // 0부터 시작하도록
		}

		sets.insert(s);
	}

	for (int color = 0; color < (1 << n); ++color) {
		bool able = true;
		for (const int s : sets) {
			if (((color & s) == 0) || ((color & s) == s)) {
				able = false;
				break;
			}
		}

		if (able) {
			cout << "Y";
			return;
		}
	}

	cout << "N";
}

int main(void) {
	int K;
	string line;
	getline(cin, line);
	K = stoi(line);

	for (int i = 0; i < K; ++i) {
		test_case();
	}

	return 0;
}