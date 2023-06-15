#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	string s1, s2;
	cin >> s1 >> s2;

	vector<int> v1(26, 0), v2(26, 0);
	for (const char c : s1) {
		++v1[c - 'a'];
	}

	for (const char c : s2) {
		++v2[c - 'a'];
	}

	int result = 0;
	for (int i = 0; i < 26; ++i) {
		result += abs(v1[i] - v2[i]);
	}

	cout << result;

	return 0;
}