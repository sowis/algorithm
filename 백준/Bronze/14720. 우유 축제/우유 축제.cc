#include <cstdio>
#include <vector>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	vector<int> store(N);
	for (int& milk : store) {
		scanf("%d", &milk);
	}

	int want = 0;
	int drink = 0;
	for (const int milk : store) {
		if (milk != want) {
			continue;
		}

		++want;
		want %= 3;
		++drink;
	}

	printf("%d\n", drink);

	return 0;
}