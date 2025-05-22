#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);

	vector<long long> items(N);
	unordered_set<long long> h_items;
	for (long long& item : items) {
		scanf("%lld", &item);
		h_items.insert(item);
	}

	unordered_set<long long> two_sum;
	for (int i = 0; i < N; ++i) {
		for (int k = i; k < N; ++k) {
			two_sum.insert(items[i] + items[k]);
		}
	}

	sort(items.begin(), items.end(), greater<long long>());

	for (int i = 0; i < N; ++i) {
		for (int k = 0; k < N; ++k) {
			if (two_sum.find(items[i] - items[k]) != two_sum.end()) {
				printf("%lld\n", items[i]);
				return 0;
			}
		}
	}
	
	return 0;
}