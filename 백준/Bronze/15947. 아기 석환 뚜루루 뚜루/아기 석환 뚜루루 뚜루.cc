#include <iostream>
#include <string> 

using namespace std;

void turu(const int N, const bool tururu = false) {
	int ru_count = (tururu ? 2 : 1);

	if (ru_count + N / 14 >= 5) {
		cout << "tu+ru*" << ru_count + N / 14;
	}
	else {
		cout << "tu";

		for (int i = 0; i < ru_count + N / 14; ++i) {
			cout << "ru";
		}
	}
}

int main(void) {
	int N;
	cin >> N;

	--N;

	if (N % 14 == 0) {
		cout << "baby";
	}
	else if (N % 14 == 1) {
		cout << "sukhwan";
	}
	else if (N % 14 == 2) {
		turu(N, true);
	}
	else if (N % 14 == 3) {
		turu(N, false);
	}
	else if (N % 14 == 4) {
		cout << "very";
	}
	else if (N % 14 == 5) {
		cout << "cute";
	}
	else if (N % 14 == 6) {
		turu(N, true);
	}
	else if (N % 14 == 7) {
		turu(N, false);
	}
	else if (N % 14 == 8) {
		cout << "in";
	}
	else if (N % 14 == 9) {
		cout << "bed";
	}
	else if (N % 14 == 10) {
		turu(N, true);
	}
	else if (N % 14 == 11) {
		turu(N, false);
	}
	else if (N % 14 == 12) {
		cout << "baby";
	}
	else if (N % 14 == 13) {
		cout << "sukhwan";
	}

	return 0;
}