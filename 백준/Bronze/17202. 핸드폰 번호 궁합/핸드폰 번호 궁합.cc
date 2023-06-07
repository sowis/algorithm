#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> number_add(const vector<int>& v) {
	vector<int> result;
	for (int i = 0; i < v.size() - 1; ++i) {
		const int number = (v[i] + v[i + 1]) % 10;
		result.push_back(number);
	}

	return result;
}

int main(void) {
	string s1, s2;
	cin >> s1 >> s2;

	vector<int> v;
	for (int i = 0; i < s1.size(); ++i) {
		v.push_back(s1[i] - '0');
		v.push_back(s2[i] - '0');
	}

	while (v.size() > 2) {
		v = number_add(v);
	}

	cout << v[0] << v[1] << "\n";

	return 0;
}