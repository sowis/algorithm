#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	vector<int> arr(3);
	for (int& num : arr) {
		scanf("%d", &num);
	}

	sort(arr.begin(), arr.end());

	printf("%d\n", arr[1]);

	return 0;
}