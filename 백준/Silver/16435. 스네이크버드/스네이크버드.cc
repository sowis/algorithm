#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N, L;
	scanf("%d%d", &N, &L);

	vector<int> fruits(N);
	for (int& fruit : fruits) {
		scanf("%d", &fruit);
	}

	sort(fruits.begin(), fruits.end());

	for (const int fruit : fruits) {
		if (fruit > L) {
			break;
		}

		++L;
	}

	printf("%d\n", L);

	return 0;
}