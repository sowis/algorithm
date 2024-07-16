#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);

	int origin = 0;
	vector<int> v1(a), v2(b), v3(c);
	for (int& num : v1) {
		scanf("%d", &num);
		origin += num;
	}

	for (int& num : v2) {
		scanf("%d", &num);
		origin += num;
	}

	for (int& num : v3) {
		scanf("%d", &num);
		origin += num;
	}

	sort(v1.begin(), v1.end(), greater<int>());
	sort(v2.begin(), v2.end(), greater<int>());
	sort(v3.begin(), v3.end(), greater<int>());

	const int price_down_count = min(min(a, b), c);

	for (int i = 0; i < price_down_count; ++i) {
		v1[i] = v1[i] * 0.9;
		v2[i] = v2[i] * 0.9;
		v3[i] = v3[i] * 0.9;
	}

	int result = 0;
	for (const int num : v1) {
		result += num;
	}

	for (const int num : v2) {
		result += num;
	}

	for (const int num : v3) {
		result += num;
	}

	printf("%d\n", origin);
	printf("%d\n", result);

	return 0;
}