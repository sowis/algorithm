#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N, L;
	scanf("%d%d", &N, &L);

	vector<pair<int, int>> ponds(N);
	for (pair<int, int>& p : ponds) {
		scanf("%d%d", &p.first, &p.second);

		--p.second;
	}

	sort(ponds.begin(), ponds.end());

	int result = 0;
	int board_end = -1;

	for (const pair<int, int>& p : ponds) {
		if (p.second <= board_end) {
			continue;
		}

		const int board_begin = max(p.first, board_end + 1);
		const int remain_pond_size = p.second - board_begin + 1;
		const int board_count = (remain_pond_size / L) + ((remain_pond_size % L) ? 1 : 0);
		board_end = board_begin + (board_count * L) - 1;
		result += board_count;
	}

	printf("%d\n", result);

	return 0;
}