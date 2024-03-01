#include <cstdio>
#include <vector>

using namespace std;

int main(void) {
	int D, K;
	scanf("%d%d", &D, &K);

	if (D == 3) {
		printf("%d\n", 1);
		printf("%d\n", K - 1);
		return 0;
	}

	vector<int> prefix(D);
	prefix[0] = 1;
	prefix[1] = 2;
	for (int i = 2; i < D; ++i) {
		prefix[i] = prefix[i - 2] + prefix[i - 1];
	}

	const int first_day_mul = prefix[D - 4];
	const int second_day_mul = prefix[D - 3];

	for (int first_day = 1; first_day * first_day_mul < K; ++first_day) {
		if ((K - (first_day * first_day_mul)) % second_day_mul) {
			continue;
		}

		const int second_day = (K - (first_day * first_day_mul)) / second_day_mul;
		printf("%d\n", first_day);
		printf("%d\n", second_day);
		return 0;
	}

	return 0;
}