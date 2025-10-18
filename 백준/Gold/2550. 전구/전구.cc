#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	vector<int> lefts(N);
	vector<int> right_idxs(N + 1);
	vector<int> right_idxs_reverse(N + 1);

	for (int& left : lefts) {
		cin >> left;
	}

	for (int i = 0; i < N; ++i) {
		int right;
		cin >> right;

		right_idxs[right] = i;
		right_idxs_reverse[i] = right;
	}

	vector<int> orders;
	for (const int left : lefts) {
		orders.push_back(right_idxs[left]);
	}

	vector<int> result;
	vector<int> parents(N, -1);
	for (const int order : orders) {
		const int target_idx = (int)(lower_bound(result.begin(), result.end(), order) - result.begin());
		if (target_idx == result.size()) {
			result.push_back(order);
		}
		else {
			result[target_idx] = order;
		}

		if (target_idx != 0) {
			parents[order] = result[target_idx - 1];
		}
	}
	
	int cur = result[result.size() - 1];
	vector<int> brights;
	while (cur != -1) {
		brights.push_back(right_idxs_reverse[cur]);
		cur = parents[cur];
	}

	sort(brights.begin(), brights.end());

	cout << brights.size() << "\n";
	for (const int bright : brights) {
		cout << bright << " ";
	}

	return 0;
}