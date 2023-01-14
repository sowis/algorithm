#include <cstdio>
#include <cmath>

using namespace std;

long long X, Y;

long long get_Z(const long long win_add) {
	return (long long)ceil(100 * (Y + win_add) / (X + win_add));
}

int main(void) {
	scanf("%lld%lld", &X, &Y);

	const long long Z = get_Z(0);
	if (Z >= 99) {
		printf("-1\n");
		return 0;
	}

	long long begin = 0, end = 1000000000;
	long long last_non_change = 0;

	while (begin < end) {
		const long long mid = (begin + end) / 2;
		if (get_Z(mid) == Z) {
			last_non_change = mid;
			begin = mid + 1;
		}
		else {
			end = mid;
		}
	}

	printf("%lld\n", last_non_change + 1);

	return 0;
}