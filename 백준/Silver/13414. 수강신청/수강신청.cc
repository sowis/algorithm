#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main(void) {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int K, L;
	cin >> K >> L;

	unordered_map<string, int> order;
	int number = 0;
	for (int i = 0; i < L; ++i) {
		string id;
		cin >> id;

		order[id] = number;
		++number;
	}

	vector<pair<int, string>> v;
	for (const pair<string, int>& p : order) {
		v.push_back({ p.second, p.first });
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < min((int)v.size(), K); ++i) {
		cout << v[i].second << "\n";
	}

	return 0;
}