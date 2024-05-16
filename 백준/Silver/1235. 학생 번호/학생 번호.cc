#include <string>
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main(void) {
	int N;
	cin >> N;

	vector<string> numbers(N);
	for (string& s : numbers) {
		cin >> s;
	}

	for (int k = 1; ; ++k) {
		bool ok = true;
		unordered_set<string> s;

		for (const string& str : numbers) {
			string cur;
			for (int i = (int)str.size() - k; i < (int)str.size(); ++i) {
				cur += str[i];
			}

			if (s.find(cur) != s.end()) {
				ok = false;
				break;
			}

			s.insert(cur);
		}

		if (ok) {
			cout << k << "\n";
			break;
		}
	}

	return 0;
}