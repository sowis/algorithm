#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> switchs(N);
	vector<int> lamps(M + 1);
	for (int i = 0; i < N; ++i) {
		int link;
		cin >> link;

		for (int k = 0; k < link; ++k) {
			int lamp;
			cin >> lamp;

			++lamps[lamp];
			switchs[i].push_back(lamp);
		}
	}

	for (const vector<int>& swt : switchs) {
		bool all_over_2 = true;
		for (int lamp : swt) {
			if (lamps[lamp] < 2) {
				all_over_2 = false;
				break;
			}
		}

		if (all_over_2) {
			cout << 1;
			return 0;
		}
	}

	cout << 0;

	return 0;
}