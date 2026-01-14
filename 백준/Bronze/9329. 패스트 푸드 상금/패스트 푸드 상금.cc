#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void test_case(void) {
	int N, M;
	cin >> N >> M;

	vector<vector<int>> needs(N);
	vector<int> prices(N);

	for (int i = 0; i < N; ++i) {
		int k;
		cin >> k;

		needs[i] = vector<int>(k);
		for (int &need : needs[i]) {
			cin >> need;
			--need; // 0번부터 시작
		}

		cin >> prices[i];
	}

	vector<int> stickers(M);
	for (int& sticker : stickers) {
		cin >> sticker;
	}

	int result = 0;
	for (int i = 0; i < N; ++i) {
		int count = 1987654321;
		for (const int sticker : needs[i]) {
			count = min(count, stickers[sticker]);
		}

		result += (count * prices[i]);
	}

	cout << result << "\n";
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		test_case();
	}

	return 0;
}