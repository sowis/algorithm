#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int to_number(const char c) {
	if ('0' <= c && c <= '9') {
		return c - '0';
	}

	return c - 'A' + 10;
}

int main(void) {
	string N;
	int B;

	cin >> N >> B;

	reverse(N.begin(), N.end());

	int result = 0;
	for (int i = 0; i < N.size(); ++i) {
		result += (to_number(N[i]) * (int)pow(B, i));
	}

	printf("%d\n", result);

	return 0;
}