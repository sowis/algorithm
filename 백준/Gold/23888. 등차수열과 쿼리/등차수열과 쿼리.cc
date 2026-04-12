#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long a, d, q;

long long gcd(long long a, long long b) {
	if (b > a) {
		swap(a, b);
	}

	while (b != 0) {
		long long div = a % b;
		a = b;
		b = div;
	}

	return a;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> a >> d;
	cin >> q;

	while (q--) {
		int op;
		cin >> op;

		if (op == 1) {
			long long l, r;
			cin >> l >> r;

			cout << (r - l + 1) * a + ((((r - 1) * r) - ((l - 2) * (l - 1))) / 2) * d << "\n";
		}
		else if (op == 2) {
			long long l, r;
			cin >> l >> r;

			if (l == r) {
				cout << a + (l - 1) * d << "\n";
			}
			else {
				cout << gcd(a + (l - 1) * d, a + l * d) << "\n";
			}
		}
	}

	return 0;
}