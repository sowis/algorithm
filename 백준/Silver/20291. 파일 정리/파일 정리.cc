#include <iostream>
#include <map>

using namespace std;

string extention(const string text) {
	string result;
	bool ok = false;
	for (const char c : text) {
		if (ok) {
			result += c;
		}

		if (c == '.') {
			ok = true;
		}
	}

	return result;
}

int main(void) {
	int N;
	cin >> N;

	map<string, int> counts;
	for (int i = 0; i < N; ++i) {
		string text;
		cin >> text;

		const string ex = extention(text);
		++counts[ex];
	}

	for (const pair<string, int>& p : counts) {
		cout << p.first << " " << p.second << "\n";
	}

	return 0;
}