#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	vector<int> fruits(N);
	
	for (int& fruit : fruits) {
		scanf("%d", &fruit);
	}

	vector<int> count(10, 0);
	int type_count = 0;
	int current_length = 0;
	int result = 0;
	int left = 0;

	for (const int fruit : fruits) {
		++count[fruit];
		++current_length;

		if (count[fruit] == 1) {
			++type_count;
		}

		while (2 < type_count) {
			--count[fruits[left]];
			--current_length;
			if (count[fruits[left]] == 0) {
				--type_count;
			}

			++left;
		}

		result = max(result, current_length);
	}

	printf("%d\n", result);

	return 0;
}