#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N;
	cin >> N;

	vector<int> arr(N);
	for (int& num : arr) {
		cin >> num;
	}

	vector<int> lis;
	for (const int num : arr) {
		const int idx = (int)(lower_bound(lis.begin(), lis.end(), num) - lis.begin());
		if (idx == lis.size()) {
			lis.push_back(num);
		}
		else {
			lis[idx] = num;
		}
	}

	const int result = N - (int)lis.size();
	cout << result;

	return 0;
}