#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void bin_sum(string& a, string& b) {
	if (a.size() < b.size()) {
		swap(a, b);
	}

	string buf;
	for (int i = 0; i < a.size() - b.size(); ++i) {
		buf += '0';
	}

	b = buf + b;
	vector<int> v(a.size() + 1);

	int up = 0;
	for (int i = a.size() - 1; i >= 0; --i) {
		const int s = up + (a[i] - '0') + (b[i] - '0');
		v[i + 1] = s % 2;
		up = s / 2;
	}

	v[0] = up;

	int begin = 0;
	for (; begin < v.size() && v[begin] == 0; ++begin);
	if (begin == v.size()) {
		--begin;
	}

	for (int i = begin; i < v.size(); ++i) {
		cout << v[i];
	}

	cout << "\n";
}

int main(void) {
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		string a, b;
		cin >> a >> b;

		bin_sum(a, b);
	}

	return 0;
}