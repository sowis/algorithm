#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<char, int> hole;

int main(void) {
	hole['A'] = 1;
	hole['a'] = 1;
	hole['B'] = 2;
	hole['b'] = 1;
	hole['D'] = 1;
	hole['d'] = 1;
	hole['e'] = 1;
	hole['g'] = 1;
	hole['O'] = 1;
	hole['o'] = 1;
	hole['P'] = 1;
	hole['p'] = 1;
	hole['Q'] = 1;
	hole['q'] = 1;
	hole['R'] = 1;
	hole['@'] = 1;

	char c;
	int result = 0;
	while (cin >> c) {
		result += hole[c];
	}

	cout << result;
	return 0;
}