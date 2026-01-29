#include <iostream>
#include <vector>

using namespace std;

bool is_valid(const int y, const int m, const int d) {
	if (m < 1 || 12 < m) {
		return false;
	}

	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
		if (d < 1 || 31 < d) {
			return false;
		}
	}
	else if (m == 4 || m == 6 || m == 9 || m == 11) {
		if (d < 1 || 30 < d) {
			return false;
		}
	}
	else {
		if (y % 4) {
			if (d < 1 || 28 < d) {
				return false;
			}
		}
		else {
			if (d < 1 || 29 < d) {
				return false;
			}
		}
	}

	return true;
}

bool is_ok(const int Y, const int M, const int D, const int y, const int m, const int d) {
	if (Y != y) {
		return y > Y;
	}

	if (M != m) {
		return m > M;
	}

	return d >= D;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int Y, M, D;
	cin >> Y >> M >> D;

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i) {
		int a, b, c;
		cin >> a >> b >> c;

		bool valid = false;
		bool safe = true;

		if (is_valid(a, b, c)) {
			valid = true;
			if (is_ok(Y, M, D, a, b, c) == false) {
				safe = false;
			}
		}

		if (is_valid(c, b, a)) {
			valid = true;
			if (is_ok(Y, M, D, c, b, a) == false) {
				safe = false;
			}
		}

		if (is_valid(c, a, b)) {
			valid = true;
			if (is_ok(Y, M, D, c, a, b) == false) {
				safe = false;
			}
		}

		if (valid == false) {
			cout << "invalid\n";
		}
		else if (safe) {
			cout << "safe\n";
		}
		else {
			cout << "unsafe\n";
		}
	}

	return 0;
}