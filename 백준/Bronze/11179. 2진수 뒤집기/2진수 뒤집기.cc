#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> num_to_binary(long long n) {
	vector<int> result;
	while (n > 0) {
		result.push_back(n % 2);
		n /= 2;
	}

	reverse(result.begin(), result.end());
	return result;
}

int main(void) {
	long long N;
	cin >> N;

	const vector<int> bi = num_to_binary(N);

	long long result = 0;
	int exp = 0;
	for (const char c : bi) {
		if (c == 1) {
			result += (long long)pow(2, exp);
		}

		++exp;
	}

	cout << result << "\n";

	return 0;
}