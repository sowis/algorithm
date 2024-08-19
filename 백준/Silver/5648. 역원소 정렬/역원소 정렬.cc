#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	vector<long long> v;
	for (int i = 0; i < N; ++i) {
		string str;
		cin >> str;

		reverse(str.begin(), str.end());
		v.push_back(stoll(str));
	}

	sort(v.begin(), v.end());

	for (const long long n : v) {
		cout << n << "\n";
	}

	return  0;
}