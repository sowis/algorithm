#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, L;
vector<int> rests;

bool can_go(const int no_rest_dist) {
	int current = no_rest_dist;
	int remain_create_rest = M;
	int rests_idx = 0;

	while (true) {
		while (rests_idx < N && current >= rests[rests_idx]) {
			current = rests[rests_idx] + no_rest_dist;
			++rests_idx;
		}

		if (current >= L) {
			return true;
		}

		if (remain_create_rest == 0) {
			return false;
		}

		--remain_create_rest;
		current += no_rest_dist;
	}
}

int main(void) {
	scanf("%d%d%d", &N, &M, &L);

	rests = vector<int>(N);
	for (int& rest : rests) {
		scanf("%d", &rest);
	}

	sort(rests.begin(), rests.end());

	int begin = 0;
	int end = L + 1;
	int result = 987654321;

	while (begin <= end) {
		const int mid = (begin + end) / 2;
		if (can_go(mid)) {
			result = min(result, mid);
			end = mid - 1;
		}
		else {
			begin = mid + 1;
		}
	}

	printf("%d\n", result);

	return 0;
}