#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	vector<int> v(3);
	for (int& n : v) {
		cin >> n;
	}

	sort(v.begin(), v.end());

	string s;
	cin >> s;

	for (const char c : s) {
		if (c == 'A') {
			cout << v[0] << " ";
		}
		else if (c == 'B') {
			cout << v[1] << " ";
		}
		else {
			cout << v[2] << " ";
		}
	}

	return 0;
}