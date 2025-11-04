#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long width;
	while (cin >> width) {
		width *= 10000000;
		long long n;
		cin >> n;

		unordered_map<long long, int> blocks;
		for (int i = 0; i < n; ++i) {
			long long block;
			cin >> block;

			++blocks[block];
		}

		long long diff_max = 0;
		long long a = -1, b = -1;
		for (const pair<long long, int>& p : blocks) {
			if (blocks.find(width - p.first) == blocks.end()) {
				continue;
			}

			if (p.first == width - p.first && blocks[p.first] == 1) {
				continue;
			}

			const long long diff = abs(p.first - (width - p.first));
			if (diff_max > diff) {
				continue;
			}

			diff_max = diff;
			a = p.first;
			b = width - p.first;
		}

		if (a > b) {
			swap(a, b);
		}

		if (a == -1 && b == -1) {
			cout << "danger\n";
		}
		else {
			cout << "yes " << a << " " << b << "\n";
		}
	}

	return 0;
}