#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	long long result = 0;
	int cur_max;
	cin >> cur_max;
	int last = cur_max;

	for (int i = 1; i < N; ++i) {
		int cur;
		cin >> cur;

		if (cur == last) {
			continue;
		}
		else if (cur < last) {
			result += last - cur;
		}
		else {
			result += max(0, cur - cur_max);
			cur_max = max(cur_max, cur);
		}

		last = cur;
	}

	cout << result;

	return 0;
}