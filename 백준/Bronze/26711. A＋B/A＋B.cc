#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	string a, b;
	cin >> a >> b;

	vector<int> v(max(a.size(), b.size()) + 1, 0);

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	int up = 0;
	for (int i = 0; i < min(a.size(), b.size()); ++i) {
		const int cur = a[i] - '0' + b[i] - '0' + up;
		up = cur / 10;
		v[i] = cur % 10;
	}

	if (a.size() > b.size()) {
		for (int i = b.size(); i < a.size(); ++i) {
			const int cur = a[i] - '0' + up;
			up = cur / 10;
			v[i] = cur % 10;
		}
	}
	else if (a.size() < b.size()) {
		for (int i = a.size(); i < b.size(); ++i) {
			const int cur = b[i] - '0' + up;
			up = cur / 10;
			v[i] = cur % 10;
		}
	}

	v[v.size() - 1] = up;
	if (v[v.size() - 1] == 0) {
		v.pop_back();
	}

	reverse(v.begin(), v.end());
	for (const int num : v) {
		printf("%d", num);
	}

	return 0;
}