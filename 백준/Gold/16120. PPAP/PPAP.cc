#include <iostream>
#include <string>
#include <stack>

using namespace std;

int N;
string str;

int main(void) {
	cin >> str;
	N = (int)str.size();

	stack<char> stk;
	for (const char c : str) {
		stk.push(c);

		if (stk.size() < 4) {
			continue;
		}

		string current;
		for (int i = 0; i < 4; ++i) {
			current += stk.top();
			stk.pop();
		}

		if (current == "PAPP") {
			stk.push('P');
		}
		else {
			for (int i = 3; i >= 0; --i) {
				stk.push(current[i]);
			}
		}
	}

	if (stk.size() == 1 && stk.top() == 'P') {
		cout << "PPAP\n";
	}
	else {
		cout << "NP\n";
	}

	return 0;
}