#include <iostream>

using namespace std;

int main(void) {
	int N;
	cin >> N;

	if (N == 1) {
		cout << 2024 << " " << 8;
	}
	else if (N == 2) {
		cout << 2025 << " " << 3;
	}
	else if (N == 3) {
		cout << 2025 << " " << 10;
	}
	else if (N == 4) {
		cout << 2026 << " " << 5;
	}
	else if (N == 5) {
		cout << 2026 << " " << 12;
	}	

	return 0;
}