#include <iostream>

using namespace std;

int main(void) {
	long long N;
	cin >> N;

	long long A, PA, B, PB;
	cin >> A >> PA >> B >> PB;

	long long max_value = 0;
	long long result_x = 0, result_y = 0;
	for (long long x = 0; x * PA <= N; ++x) {
		const long long y = (N - x * PA) / PB;
		if (x * A + y * B > max_value) {
			max_value = x * A + y * B;
			result_x = x;
			result_y = y;
		}
	}

	cout << result_x << " " << result_y << "\n";

	return 0;
}