#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N, I;
	cin >> N >> I;

	vector<string> v(N);
	for (string& s : v) {
		cin >> s;
	}

	sort(v.begin(), v.end());

	cout << v[I - 1];

	return 0;
}