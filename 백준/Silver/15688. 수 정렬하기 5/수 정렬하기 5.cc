#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	vector<int> arr(N);
	for (int& num : arr) {
		scanf("%d", &num);
	}

	sort(arr.begin(), arr.end());

	for (const int num : arr) {
		printf("%d\n", num);
	}

	return 0;
}