#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

const char* cheese = "Cheese";

int main(void) {
	int N;
	cin >> N;

	unordered_set<string> cheeses;
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;

		if (s.size() < 6) {
			continue;
		}

		bool ok = true;
		for (int offset = 0; offset < 6; ++offset) {
			if (cheese[offset] != s[s.size() - 6 + offset]) {
				ok = false;
				break;
			}
		}

		if (ok) {
			cheeses.insert(s);
		}
	}

	if (cheeses.size() >= 4) {
		cout << "yummy";
	}
	else {
		cout << "sad";
	}

	return 0;
}