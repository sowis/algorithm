#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

vector<vector<string>> cache(13, vector<string>(2));

string foo(const int exp, const bool print) {
	string& c = cache[exp][print ? 1 : 0];
	if (c != "") {
		return c;
	}

	if (print == false) {
		for (int i = 0; i < (int)pow(3, exp); ++i) {
			c += " ";
		}

		return c;
	}

	if (exp == 0) {
		c += "-";
		return c;
	}

	c = foo(exp - 1, true) + foo(exp - 1, false) + foo(exp - 1, true);
	return c;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	while (cin >> N) {
		const string result = foo(N, true);
		cout << result << "\n";
	}

	return 0;
}