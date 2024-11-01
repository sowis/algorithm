#include <iostream>
#include <unordered_map>

using namespace std;

int main(void) {
	unordered_map<char, int> scores;
	scores['k'] = 0;
	scores['p'] = 1;
	scores['n'] = 3;
	scores['b'] = 3;
	scores['r'] = 5;
	scores['q'] = 9;

	int result = 0;
	for (int i = 0; i < 64; ++i) {
		char input;
		cin >> input;

		if (input == '.') {
			continue;
		}

		if ('a' <= input && input <= 'z') {
			result -= scores[input];
		}
		else {
			result += scores[input - 'A' + 'a'];
		}
	}
	
	cout << result;

	return 0;
}