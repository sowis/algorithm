#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<pair<int, int>> results;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	results.push_back({ 1, -9999 });
	int target_height = 1;
	for (int i = 0; i < M; ++i) {
		int ans;
		cin >> ans;

		results.push_back({ 1 + ans, target_height });
		++target_height;
		results.push_back({ -1, -1 });
	}

	cout << results.size() << "\n";
	for (const pair<int, int>& p : results) {
		if (p.first == -1) {
			cout << "P\n";
		}
		else {
			cout << "U " << p.first << " " << p.second << "\n";
		}
	}

	return 0;
}