#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int N;
	cin >> N;

	vector<int> count(3, 0);
	vector<char> name{ 'B', 'S', 'A' };
	for (int i = 0; i < N; ++i) {
		char c;
		cin >> c;

		if (c == 'B') {
			++count[0];
		}
		else if (c == 'S') {
			++count[1];
		}
		else {
			++count[2];
		}
	}

	if (count[0] == count[1] && count[1] == count[2]) {
		cout << "SCU";
		return 0;
	}

	int max_count = 0;
	for (int c : count) {
		max_count = max(max_count, c);
	}

	for (int i = 0; i < 3; ++i) {
		if (count[i] == max_count) {
			cout << name[i];
		}
	}

	return 0;
}