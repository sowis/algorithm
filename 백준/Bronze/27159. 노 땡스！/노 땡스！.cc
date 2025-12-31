#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N;
	cin >> N;

	vector<int> v(N);
	for (int& num : v) {
		cin >> num;
	}

	sort(v.begin(), v.end());

	int last = -1;
	int result = 0;
	for (int num : v) {
		if (num == last + 1) {
			last = num;
			continue;
		}

		last = num;
		result += num;
	}

	cout << result;

	return 0;
}