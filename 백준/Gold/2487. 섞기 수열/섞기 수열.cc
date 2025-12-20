#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int remain = a % b;
		a = b;
		b = remain;
	}

	return a;
}

inline int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}

int main(void) {	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	vector<int> last(N + 1);
	vector<int> next(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> last[i];
		next[last[i]] = i;
	}

	vector<int> cycle_sizes(N + 1, -1);
	for (int i = 1; i <= N; ++i) {
		if (cycle_sizes[i] != -1) {
			continue;
		}

		vector<int> cycle_in_pos{ i };
		int sz = 1;
		int pos = next[i];

		while (pos != i) {
			cycle_in_pos.push_back(pos);
			++sz;
			pos = next[pos];
		}

		for (const int inner_pos : cycle_in_pos) {
			cycle_sizes[inner_pos] = sz;
		}
	}

	int result = cycle_sizes[1];
	for (int i = 2; i <= N; ++i) {
		result = lcm(result, cycle_sizes[i]);
	}

	cout << result;

	return 0;
}