#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string DNA;
vector<vector<int>> cache;

int solve(const int begin, const int end) {
	if (end - begin < 2) {
		return 0;
	}

	int& c = cache[begin][end];
	if (c != -1) {
		return c;
	}

	c = 0;
	if ((DNA[begin] == 'a' && DNA[end - 1] == 't') || (DNA[begin] == 'g' && DNA[end - 1] == 'c')) {
		c = max(c, 2 + solve(begin + 1, end - 1));
	}

	for (int mid = begin + 1; mid < end; ++mid) {
		c = max(c, solve(begin, mid) + solve(mid, end));
	}

	return c;
}

int main(void) {
	cin >> DNA;

	cache = vector<vector<int>>(DNA.size() + 1, vector<int>(DNA.size() + 1, -1));
	cout << solve(0, (int)DNA.size());

	return 0;
}