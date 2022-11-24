#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

int main(void) {
	int N;
	cin >> N;

	string expression_string;
	cin >> expression_string;

	unordered_map<char, double> values;
	char target = 'A';
	for (int i = 0; i < N; ++i) {
		cin >> values[target];
		++target;
	}

	stack<double> stk;
	for (const char c : expression_string) {
		if (c == '+') {
			const double second = stk.top();
			stk.pop();
			const double first = stk.top();
			stk.pop();

			const double result = first + second;
			stk.push(result);
		}
		else if (c == '-') {
			const double second = stk.top();
			stk.pop();
			const double first = stk.top();
			stk.pop();

			const double result = first - second;
			stk.push(result);
		}
		else if (c == '*') {
			const double second = stk.top();
			stk.pop();
			const double first = stk.top();
			stk.pop();

			const double result = first * second;
			stk.push(result);
		}
		else if (c == '/') {
			const double second = stk.top();
			stk.pop();
			const double first = stk.top();
			stk.pop();

			const double result = first / second;
			stk.push(result);
		}
		else {
			const double value = values[c];
			stk.push(value);
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << stk.top();

	return 0;
}