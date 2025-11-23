#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> A;
long long L;

bool parametric_search(const int x) {
	long long good = 0;
	for (const int a : A) {
		if (x >= a) {
			good += x;
		}
		else {
			good += (2 * (x - a));
		}
	}

	return good >= L;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	A = vector<int>(N);
	for (int& num : A) {
		cin >> num;
	}

	cin >> L;

	long long left = 0;
	long long right = 1000000000;
	long long result = 1987654321;

	while (left <= right) {
		const long long mid = (left + right) / 2;
		if (parametric_search(mid)) {
			result = min(result, mid);
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	cout << result;

	return 0;
}