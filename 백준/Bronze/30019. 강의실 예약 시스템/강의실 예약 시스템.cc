#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<int> last(N + 1, -1);

	for (int i = 0; i < M; ++i) {
		int k, s, e;
		cin >> k >> s >> e;

		if (last[k] > s) {
			cout << "NO\n";
			continue;
		}

		cout << "YES\n";
		last[k] = e;
	}

	return 0;
}