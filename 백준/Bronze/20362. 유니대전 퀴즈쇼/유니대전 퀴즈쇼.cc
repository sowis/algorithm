#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int main(void) {
	int N;
	string name;

	cin >> N >> name;

	unordered_set<string> results;
	vector<pair<string, string>> v(N);
	string ans;
	for (pair<string, string>& p : v) {
		cin >> p.first >> p.second;

		if (p.first == name) {
			ans = p.second;
		}
	}

	for (const pair<string, string>& p : v) {
		if (p.first == name) {
			break;
		}

		if (p.second == ans) {
			results.insert(p.first);
		}
	}

	cout << results.size();

	return 0;
}