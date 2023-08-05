#include <cstdio>
#include <vector>

using namespace std;

int main(void) {
	vector<int> arr;
	arr.push_back(0);

	for (int num = 1; arr.size() <= 1000; ++num) {
		for (int i = 0; i < num; ++i) {
			arr.push_back(num);
		}
	}

	int a, b;
	scanf("%d%d", &a, &b);

	int result = 0;
	for (int i = a; i <= b; ++i) {
		result += arr[i];
	}

	printf("%d\n", result);

	return 0;
}