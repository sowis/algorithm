#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int N;
	cin >> N;

	bool odd = false;
	bool even = false;
	bool im_odd = false;

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			int value;
			cin >> value;

			if (value == 0) {
				continue;
			}

			if (value == 1) {
				if ((y + x) % 2) {
					odd = true;
				}
				else {
					even = true;
				}
			}

			if (value == 2) {
				if ((y + x) % 2) {
					im_odd = true;
				}
			}
		}
	}

	if (odd && even) {
		cout << "Kiriya\n";
		return 0;
	}

	if (odd == false && even == false) {
		cout << "Lena\n";
		return 0;
	}

	if (im_odd && even) {
		cout << "Lena\n";
		return 0;
	}

	if (im_odd == false && odd) {
		cout << "Lena\n";
		return 0;
	}

	cout << "Kiriya\n";

	return 0;
}