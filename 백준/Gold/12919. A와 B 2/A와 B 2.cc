#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool solve(const string &cur, const string& target) {
	if (cur == target) {
		return true;
	}

	if (cur.size() == target.size()) {
		return false;
	}

	string rev_cur = cur;
	reverse(rev_cur.begin(), rev_cur.end());

	if (target.find(cur) == string::npos && target.find(rev_cur) == string::npos) {
		return false;
	}

	return solve(cur + 'A', target) || solve('B' + rev_cur, target);
}

int main(void) {
	string S, T;
	cin >> S >> T;

	cout << (solve(S, T) ? 1 : 0);

	return 0;
}