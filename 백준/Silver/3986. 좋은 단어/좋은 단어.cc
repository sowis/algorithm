#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void) {
	int N;
	cin >> N;

	int result = 0;
	for (int i = 0; i < N; ++i) {
		string input;
		cin >> input;

		stack<char> stk;
		for (const char c : input) {
			if (stk.empty()) {
				stk.push(c);
			}
			else if (stk.top() == c) {
				stk.pop();
			}
			else {
				stk.push(c);
			}
		}

		if (stk.empty()) {
			++result;
		}
	}

	cout << result << "\n";

	return 0;
}