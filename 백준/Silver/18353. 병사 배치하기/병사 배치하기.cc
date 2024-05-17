#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	vector<int> arr(N);
	for (int& num : arr) {
		scanf("%d", &num);
	}

	reverse(arr.begin(), arr.end());

	vector<int> lis;
	for (const int num : arr) {
		vector<int>::iterator it = lower_bound(lis.begin(), lis.end(), num);
		if (it == lis.end()) {
			lis.push_back(num);
		}
		else {
			*it = num;
		}
	}

	printf("%d\n", N - (int)lis.size());

	return 0;
}