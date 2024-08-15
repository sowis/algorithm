#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<char>> v = { {'A', 'B', 'C'}, {'B', 'A', 'B', 'C'}, {'C', 'C', 'A', 'A', 'B', 'B'} };
vector<string> id = { "Adrian", "Bruno", "Goran" };

int main(void) {
	int N;
	cin >> N;

	string ans;
	cin >> ans;

	vector<int> rights(3, 0);
	for (int i = 0; i < N; ++i) {
		for (int k = 0; k < 3; ++k) {
			if (ans[i] == v[k][i % v[k].size()]) {
				++rights[k];
			}
		}
	}

	vector<int> max_right;
	int max_right_count = -1;

	for (int i = 0; i < 3; ++i) {
		if (rights[i] > max_right_count) {
			max_right_count = rights[i];
			max_right.clear();
			max_right.push_back(i);
		}
		else if (rights[i] == max_right_count) {
			max_right.push_back(i);
		}
	}

	cout << max_right_count << "\n";
	for (const int i : max_right) {
		cout << id[i] << "\n";
	}

	return 0;
}