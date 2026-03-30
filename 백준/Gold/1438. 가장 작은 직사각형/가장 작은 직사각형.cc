#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <limits>

using namespace std;

int N;
vector<pair<int, int>> poss;
vector<int> x_pos;

int main(void) {
	cin >> N;

	unordered_set<int> x_set, y_set;
	for (int i = 0; i < N; ++i) {
		int x, y;
		cin >> x >> y;

		poss.push_back({ x, y });
		x_set.insert(x);
		y_set.insert(y);
	}

	for (const int x : x_set) {
		x_pos.push_back(x);
	}

	sort(x_pos.begin(), x_pos.end());
	int result = numeric_limits<int>::max();

	for (int i = 0; i < x_pos.size(); ++i) {
		const int x_begin = x_pos[i];
		for (int k = i; k < x_pos.size(); ++k) {
			const int x_end = x_pos[k];
			
			vector<int> y_poss;
			for (const pair<int, int>& p : poss) {
				if (x_begin <= p.first && p.first <= x_end) {
					y_poss.push_back(p.second);
				}
			}

			if (y_poss.size() < N / 2) {
				continue;
			}

			sort(y_poss.begin(), y_poss.end());

			for (int left = 0; left < (int)y_poss.size() - (N / 2) + 1; ++left) {
				const int y_begin = y_poss[left];
				const int y_end = y_poss[left + (N / 2) - 1];

				result = min(result, (x_end - x_begin + 2) * (y_end - y_begin + 2));
			}
		}
	}

	cout << result;

	return 0;
}