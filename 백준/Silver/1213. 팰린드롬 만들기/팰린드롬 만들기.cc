#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main(void) {
	string input;
	cin >> input;

	map<char, int> counts;
	for (const char c : input) {
		++counts[c];
	}

	char odd_char = -1;
	if (input.size() % 2) {
		bool odd = false;
		for (const auto& p : counts) {
			if (p.second % 2) {
				if (odd == false) {
					odd = true;
					odd_char = p.first;
					--counts[p.first];
				}
				else {
					cout << "I'm Sorry Hansoo";
					return 0;
				}
			}
		}
	}
	else {
		for (const auto& p : counts) {
			if (p.second % 2) {
				cout << "I'm Sorry Hansoo";
				return 0;
			}
		}
	}

	string result = "";
	for (const auto& p : counts) {
		for (int i = 0; i < p.second / 2; ++i) {
			result += p.first;
		}
	}

	string result2 = result;
	reverse(result2.begin(), result2.end());

	if (odd_char != -1) {
		result += odd_char;
	}

	result += result2;

	cout << result;

	return 0;
}