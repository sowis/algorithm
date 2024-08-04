#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	string s;
	cin >> s;

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		int a, b;
		cin >> a >> b;

		swap(s[a], s[b]);
	}

	cout << s;

	return 0;
}