#include <cstdio>
#include <vector>
#include <unordered_set>

using namespace std;

unordered_set<int> cache;

int main(void) {
	vector<int> trinum;

	int psum = 0;
	for (int i = 1; psum <= 1000; ++i) {
		psum += i;
		trinum.push_back(psum);
	}

	for (int i = 0; i < trinum.size(); ++i) {
		if (trinum[i] > 1000) {
			break;
		}

		for (int k = i; k < trinum.size(); ++k) {
			if (trinum[i] + trinum[k] > 1000) {
				break;
			}

			for (int j = k; j < trinum.size(); ++j) {
				if (trinum[i] + trinum[k] + trinum[j] > 1000) {
					break;
				}

				cache.insert(trinum[i] + trinum[k] + trinum[j]);
			}
		}
	}

	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		int target;
		scanf("%d", &target);

		const int result = (cache.find(target) == cache.end()) ? 0 : 1;
		printf("%d\n", result);
	}

	return 0;
}