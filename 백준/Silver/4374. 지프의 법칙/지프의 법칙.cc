#include <iostream>
#include <string>
#include <unordered_map>
#include <regex>
#include <vector>
#include <algorithm>

using namespace std;

string lower(const string& s) {
	string result = s;
	for (char& c : result) {
		c = tolower(c);
	}

	return result;
}

int main(void) {
	unordered_map<string, int> counts;

	int N;
	while (cin >> N) {
		counts.clear();
		string str;

		while (true) {
			cin >> str;

			if (str == "EndOfText") {
				break;
			}

			regex e("\\w+");
			regex_iterator<string::iterator> rit(str.begin(), str.end(), e);
			regex_iterator<string::iterator> rend;

			while (rit != rend) {
				++counts[lower(rit->str())];
				++rit;
			}
		}

		vector<string> results;
		for (const pair<string, int>& p : counts) {
			if (p.second != N) {
				continue;
			}

			results.push_back(p.first);
		}

		sort(results.begin(), results.end());

		if (results.empty()) {
			cout << "There is no such word.\n\n";
		}
		else {
			for (const string& result : results) {
				cout << result << "\n";
			}

			cout << "\n";
		}
	}

	return 0;
}