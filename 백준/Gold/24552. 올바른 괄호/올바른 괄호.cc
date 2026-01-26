#include <iostream>
#include <string>
#include <stack>

using namespace std;

string str;

int main(void) {
	cin >> str;

	stack<pair<char, int>> stk;
	int error_idx = -1;
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == '(') {
			stk.push({ str[i], i });
		}
		else {
			if (stk.empty()) {
				error_idx = i;
				break;
			}

			stk.pop();
		}
	}

	if (stk.empty() == false) {
		error_idx = stk.top().second;
	}

	if (str[error_idx] == '(') {
		int result = 0;
		for (int i = error_idx; i < str.size(); ++i) {
			if (str[i] == '(') {
				++result;
			}
		}

		cout << result;
	}
	else {
		int result = 0;
		for (int i = 0; i <= error_idx; ++i) {
			if (str[i] == ')') {
				++result;
			}
		}

		cout << result;
	}

	return 0;
}