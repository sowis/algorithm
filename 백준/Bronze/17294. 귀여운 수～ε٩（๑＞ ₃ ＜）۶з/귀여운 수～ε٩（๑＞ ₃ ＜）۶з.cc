#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void) {
	string str;
	cin >> str;

	vector<int> v;
	for (const char c : str) {
		v.push_back(c - '0');
	}

	if (v.size() == 1) {
		cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";
		return 0;
	}

	const int diff = v[0] - v[1];
	for (int i = 2; i < v.size(); ++i) {
		if (v[i - 1] - v[i] != diff) {
			cout << "흥칫뿡!! <(￣ ﹌ ￣)>";
			return 0;
		}
	}

	cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";

	return 0;
}