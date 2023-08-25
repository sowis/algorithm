#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int finds(const vector<string>& v, const string& name) {
	for (int i = 0; i < (int)v.size(); ++i) {
		if (v[i] == name) {
			return i;
		}
	}

	return -1;
}

int main(void) {
	int N;
	cin >> N;

	vector<string> ch(N);
	int target = -1;
	for (string& s : ch) {
		cin >> s;
	}

	string result;
	const int kbs1 = finds(ch, "KBS1");
	for (int i = 0; i < kbs1; ++i) {
		result += '1';
	}

	for (int i = kbs1; i > 0; --i) {
		result += '4';
		swap(ch[i], ch[i - 1]);
	}

	const int kbs2 = finds(ch, "KBS2");
	for (int i = 0; i < kbs2; ++i) {
		result += '1';
	}

	for (int i = 1; i < kbs2; ++i) {
		result += '4';
	}

	cout << result << "\n";

	return 0;
}