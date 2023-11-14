#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> m = { 3, 2, 1, 2, 4, 3, 1, 3, 1, 1, 3, 1, 3, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };

vector<int> stov(const string& s) {
	vector<int> result;
	for (const char c : s) {
		result.push_back(m[c - 'A']);
	}

	return result;
}

vector<int> merge(const vector<int>& v1, const vector<int>& v2) {
	vector<int> result;
	int i1 = 0, i2 = 0;
	while (i1 < v1.size() && i2 < v2.size()) {
		result.push_back(v1[i1]);
		++i1;
		result.push_back(v2[i2]);
		++i2;
	}

	while (i1 < v1.size()) {
		result.push_back(v1[i1]);
		++i1;
	}

	while (i2 < v2.size()) {
		result.push_back(v2[i2]);
		++i2;
	}

	return result;
}

vector<int> next(const vector<int>& v) {
	vector<int> result;
	for (int i = 0; i < v.size() - 1; ++i) {
		result.push_back((v[i] + v[i + 1]) % 10);
	}

	return result;
}

int main(void) {
	int N, M;
	cin >> N >> M;

	string s1, s2;
	cin >> s1 >> s2;

	vector<int> v = merge(stov(s1), stov(s2));
	while (v.size() > 2) {
		v = next(v);
	}

	if (v[0] != 0) {
		cout << v[0];
	}

	cout << v[1] << "%\n";

	return 0;
}