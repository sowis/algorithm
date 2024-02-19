#include <iostream>
#include <string>
#include <vector>

using namespace std;

constexpr int DIV = 10007;

vector<vector<int>> cache(1001, vector<int>(1001, -1));

int solve(const string& str, const int begin, const int end) {
	if (begin > end) {
		return 0;
	}

	int& c = cache[begin][end];
	if (c != -1) {
		return c;
	}

	if (begin == end) {
		return c = 1;
	}

	int result = (solve(str, begin + 1, end) + solve(str, begin, end - 1) - solve(str, begin + 1, end - 1)) % DIV;
	if (result < 0) {
		result += DIV;
	}

	if (str[begin] == str[end]) {
		result += (solve(str, begin + 1, end - 1) + 1);
		result %= DIV;
	}

	return c = result;
}

int main(void) {
	string str;
	cin >> str;

	const int result = solve(str, 0, str.size() - 1);
	cout << result << "\n";

	return 0;
}