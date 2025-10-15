#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	string target;
	cin >> target;

	vector<int> counts(26, 0);
	for (const char c : target) {
		++counts[c - 'a'];
	}

	bool is_even = true;
	bool is_odd = true;
	for (const int count : counts) {
		if (count == 0) {
			continue;
		}

		if (count % 2 == 1) {
			is_even = false;
		}
		else {
			is_odd = false;
		}
	}

	if (is_even) {
		cout << 0;
	}
	else if (is_odd) {
		cout << 1;
	}
	else {
		cout << 2;
	}

	return 0;
}