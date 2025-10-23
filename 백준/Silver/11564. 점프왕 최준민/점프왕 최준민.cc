#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	long long k, a, b;
	cin >> k >> a >> b;

	long long left = abs(a);
	long long right = abs(b);

	if (left > right) {
		swap(left, right);
	}

	if ((a < 0 && b < 0) || (0 < a && 0 < b)) {
		long long result =  right / k - left / k;
		if (left % k == 0) {
			++result;
		}

		cout << result;
	}
	else {
		cout << left / k + right / k + 1;
	}

	return 0;
}