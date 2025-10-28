#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, K;
vector<int> ranks[21];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		string name;
		cin >> name;

		ranks[name.size()].push_back(i);
	}

	long long result = 0;
	for (int len = 2; len <= 20; ++len) {
		int left = 0;
		int right = 0;

		while (true) {
			++right;
			if (right >= ranks[len].size()) {
				break;
			}

			while (left < right && ranks[len][right] - ranks[len][left] > K) {
				++left;
			}

			result += (long long)right - left;
		}
	}

	cout << result;

	return 0;
}