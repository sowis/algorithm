#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool possible(const string& s1, const string& s2) {
	vector<int> c1(27, 0), c2(27, 0);

	for (const char c : s1) {
		++c1[c - 'a'];
	}

	for (const char c : s2) {
		++c2[c - 'a'];
	}

	for (int i = 0; i < 27; ++i) {
		if (c1[i] != c2[i]) {
			return false;
		}
	}

	return true;
}

int main(void) {
	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		string s1, s2;
		cin >> s1 >> s2;

		if (possible(s1, s2)) {
			cout << "Possible\n";
		}
		else {
			cout << "Impossible\n";
		}
	}

	return 0;
}