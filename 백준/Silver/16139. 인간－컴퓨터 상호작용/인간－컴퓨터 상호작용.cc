#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string s;
	cin >> s;

	int q;
	cin >> q;

	vector<vector<int>> psum('z' - 'a' + 1, vector<int>(s.size() + 1, 0));
	psum[s[0] - 'a'][0] = 1;
	for (int i = 1; i < s.size(); ++i) {
		for (int k = 0; k < 'z' - 'a' + 1; ++k) {
			psum[k][i] = psum[k][i - 1];
		}

		++psum[s[i] - 'a'][i];
	}

	for (int i = 0; i < q; ++i) {
		char c;
		int begin, end;
		cin >> c >> begin >> end;

		int result = psum[c - 'a'][end];
		if (begin != 0) {
			result -= psum[c - 'a'][begin - 1];
		}

		cout << result << "\n";
	}

	return 0;
}