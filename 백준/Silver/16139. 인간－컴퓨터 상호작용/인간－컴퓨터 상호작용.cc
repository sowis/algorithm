#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	string s;
	cin >> s;

	int q;
	cin >> q;

	vector<vector<int>> psum('z' - 'a' + 1, vector<int>(s.size() + 1));
	for (char c = 'a'; c <= 'z'; ++c) {
		psum[c - 'a'][0] = ((s[0] == c) ? 1 : 0);
		for (int i = 1; i < s.size(); ++i) {
			psum[c - 'a'][i] = psum[c - 'a'][i - 1];

			if (s[i] == c) {
				++psum[c - 'a'][i];
			}
		}
	}

	for (int i = 0; i < q; ++i) {
		char c;
		int begin, end;
		cin >> c >> begin >> end;

		int result = psum[c - 'a'][end];
		if (begin != 0) {
			result -= psum[c - 'a'][begin - 1];
		}

		printf("%d\n", result);
	}

	return 0;
}