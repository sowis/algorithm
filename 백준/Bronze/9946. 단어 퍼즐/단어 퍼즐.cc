#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> str_to_v(const string& s) {
	vector<int> v(27, 0);
	for (const char c : s) {
		++v[c - 'a'];
	}

	return v;
}

bool ok(const string& s1, const string& s2) {
	const vector<int> v1 = str_to_v(s1);
	const vector<int> v2 = str_to_v(s2);

	for (int i = 0; i < 27; ++i) {
		if (v1[i] != v2[i]) {
			return false;
		}
	}

	return true;
}

int main(void) {
	int count = 1;
	while (true) {
		string a, b;
		cin >> a >> b;

		if (a == "END") {
			break;
		}

		cout << "Case " << count << ": ";
		cout << (ok(a, b) ? "same" : "different") << "\n";
		++count;
	}

	return 0;
}