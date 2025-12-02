#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
string str;
vector<int> cache;

int solve(const int i) {
	int& c = cache[i];
	if (c != -1) {
		return c;
	}

	if (i == N) {
		return c = 1;
	}

	if (i > N) {
		return c = 0;
	}

	if (str[i] == '0') {
		return c = 0;
	}

	int result = solve(i + 1);

	if (str[i] <= '2') {
		result += solve(i + 2);
	}

	if (i + 1 < N && str[i] == '3' && str[i + 1] <= '4') {
		result += solve(i + 2);
	}

	return c = result;
}

int main(void) {
	cin >> str;

	N = (int)str.size();
	cache = vector<int>(N + 2, -1);
	cout << solve(0);

	return 0;
}