#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main(void) {
	string input;
	cin >> input;

	unordered_set<string> results;

	for (int sz = 1; sz <= input.size(); ++sz) {
		for (int begin = 0; begin <= input.size() - sz; ++begin) {
			results.insert(input.substr(begin, sz));
		}
	}

	cout << results.size() << "\n";

	return 0;
}