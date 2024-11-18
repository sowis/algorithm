#include <cstdio>
#include <unordered_map>

using namespace std;

int main(void) {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);

	unordered_map<int, int> count;

	for (int i = 1; i <= a; ++i) {
		for (int k = 1; k <= b; ++k) {
			for (int j = 1; j <= c; ++j) {
				++count[i + k + j];
			}
		}
	}

	int value = 0;
	int max_count = 0;
	for (const pair<int, int>& p : count) {
		if (p.second > max_count) {
			max_count = p.second;
			value = p.first;
		}
		else if (p.second == max_count) {
			if (p.first < value) {
				value = p.first;
			}
		}
	}

	printf("%d\n", value);

	return 0;
}