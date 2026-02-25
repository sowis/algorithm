#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> edges[11];

int main(void) {
	int A, B, C;
	cin >> A >> B >> C;

	for (int x = 1; x <= 10; ++x) {
		for (int y = 1; y <= 10; ++y) {
			if (A * x + B * y == C) {
				edges[x].push_back(y);
			}
		}
	}

	for (int i = 1; i <= 10; ++i) {
		if (edges[i].empty()) {
			cout << 0 << "\n";
			continue;
		}

		sort(edges[i].begin(), edges[i].end());
		for (const int num : edges[i]) {
			cout << num << " ";
		}

		cout << "\n";
	}

	return 0;
}