#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <deque>

using namespace std;

int N, I, M;
vector<pair<int, int>> fishs; // 물고기 위치

int fish_count(const int begin_y, const int begin_x, const int net_height, const int net_width) {
	int result = 0;
	for (const pair<int, int>& fish : fishs) {
		if (begin_y <= fish.first && fish.first <= begin_y + net_height
			&& begin_x <= fish.second && fish.second <= begin_x + net_width) {
			++result;
		}
	}

	return result;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> I >> M;
	fishs = vector<pair<int, int>>(M);
	for (pair<int, int>& fish : fishs) {
		cin >> fish.first >> fish.second;
		--fish.first; // 0, 0부터 시작하도록..
		--fish.second; // 0, 0부터 시작하도록..
	}

	int result = 0;
	for (int fish_1 = 0; fish_1 < M; ++fish_1) {
		for (int fish_2 = 0; fish_2 < M; ++fish_2) {
			const int begin_y = min(fishs[fish_1].first, fishs[fish_2].first);
			const int begin_x = min(fishs[fish_1].second, fishs[fish_2].second);

			for (int net_height = 1; net_height < I / 2; ++net_height) {
				const int net_weight = I / 2 - net_height;
				result = max(result, fish_count(begin_y, begin_x, net_height, net_weight));
			}
		}
	}

	cout << result;

	return 0;
}