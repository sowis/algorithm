#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	vector<bool> v(200, false);

	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;

	v[s1[0]] = true;
	v[s2[0]] = true;
	v[s3[0]] = true;

	if (v['k'] && v['l'] && v['p']) {
		cout << "GLOBAL";
	}
	else {
		cout << "PONIX";
	}

	return 0;
}